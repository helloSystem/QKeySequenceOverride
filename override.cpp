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

    // The key sequence is wanted in a "portable" format,
    // suitable for reading and writing to a file.
    // Do not rewrite this.
    if (format == 1) {
        return(result);
    }
        
    // Replacements based on table from
    // https://github.com/qt/qtbase/blob/7dd81686e8e9ee86624c5bcca10688cfb360dcb8/src/gui/kernel/qkeysequence.cpp#L73-L94
    result.replace(QCoreApplication::translate("QShortcut", "Esc"), QChar(0x238B));
    result.replace(QCoreApplication::translate("QShortcut", "Tab"), QChar(0x21E5));    
    result.replace(QCoreApplication::translate("QShortcut", "Backtab"), QChar(0x21E4));
    result.replace(QCoreApplication::translate("QShortcut", "Backspace"), QChar(0x232B));
    result.replace(QCoreApplication::translate("QShortcut", "Return"), QChar(0x21B5));
    result.replace(QCoreApplication::translate("QShortcut", "Enter"), QChar(0x2324));    
    result.replace(QCoreApplication::translate("QShortcut", "Del"), QChar(0x2326));
    result.replace(QCoreApplication::translate("QShortcut", "Home"), QChar(0x2196));
    result.replace(QCoreApplication::translate("QShortcut", "End"), QChar(0x2198));
    result.replace(QCoreApplication::translate("QShortcut", "Left"), QChar(0x2190));    
    result.replace(QCoreApplication::translate("QShortcut", "Up"), QChar(0x2191));
    result.replace(QCoreApplication::translate("QShortcut", "Right"), QChar(0x2192));
    result.replace(QCoreApplication::translate("QShortcut", "Down"), QChar(0x2193));
    result.replace(QCoreApplication::translate("QShortcut", "PgUp"), QChar(0x21DE));    
    result.replace(QCoreApplication::translate("QShortcut", "PgDown"), QChar(0x21DF));
    result.replace(QCoreApplication::translate("QShortcut", "Shift"), QChar(kShiftUnicode));
    result.replace(QCoreApplication::translate("QShortcut", "Ctrl"), QChar(kCommandUnicode));
    result.replace(QCoreApplication::translate("QShortcut", "Meta"), QChar(kOptionUnicode));
    result.replace(QCoreApplication::translate("QShortcut", "Alt"), QCoreApplication::translate("QShortcut", "Ctrl"));
    result.replace(QCoreApplication::translate("QShortcut", "CapsLock"), QChar(0x21EA));
    
    result.replace("++", "_PLUS_");
    result.replace("+", "");    
    result.replace("_PLUS_", "+");
    
    return(result);
}
