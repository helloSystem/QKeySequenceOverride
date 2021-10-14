#include <QApplication>
#include <QKeySequence>
#include <QDebug>

#include <QtGui/qtguiglobal.h>
#include <QtCore/qstring.h>
#include <QtCore/qobjectdefs.h>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#define _GNU_SOURCE
#include <dlfcn.h>

// Override
// QString toString(SequenceFormat format = PortableText) const;
// which is defined in /usr/local/include/qt5/QtGui/qkeysequence.h
// and is implemented in
// https://github.com/qt/qtbase/blob/7dd81686e8e9ee86624c5bcca10688cfb360dcb8/src/gui/kernel/qkeysequence.cpp#L1666-L1678

// Found this by running
// strings /usr/local/lib/qt5/* | grep KeySeq | grep tring | sort | uniq
const char* FUNC_SYMBOL = "_ZNK12QKeySequence8toStringENS_14SequenceFormatE";

static const int kShiftUnicode = 0x21E7;
static const int kControlUnicode = 0x2303;
static const int kOptionUnicode = 0x2325;
static const int kCommandUnicode = 0x2318;

typedef QString (*orig_func_f_type)(const QKeySequence *, QKeySequence::SequenceFormat format);

QString QKeySequence::toString(SequenceFormat format) const
{

    // Use some nuts function pointer black magic to access the original function
    orig_func_f_type orig_func;
    orig_func = (orig_func_f_type)dlsym(RTLD_NEXT, FUNC_SYMBOL);
    QString result = orig_func(this, format);
    
    // Table: https://github.com/qt/qtbase/blob/7dd81686e8e9ee86624c5bcca10688cfb360dcb8/src/gui/kernel/qkeysequence.cpp#L73-L94
    result.replace(QCoreApplication::translate("QShortcut", "Ctrl"), QChar(kCommandUnicode));
    result.replace(QCoreApplication::translate("QShortcut", "Shift"), QChar(kShiftUnicode));
    result.replace("+", "");
    
    return(result);


}


// env LD_PRELOAD=$(readlink -f libQKeySequenceOverride.so.1.0.0) menubar
