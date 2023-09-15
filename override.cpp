class QString;
class QChar;
#define _GNU_SOURCE
#include <dlfcn.h>
#include <QKeySequence>
typedef QString (*orig_func_f_qstring_from_qchars)(const ushort * unicode, int size);
typedef QString (*orig_func_f_translate)(const char * context, const char * key, const char * disambiguation, int n);
typedef QString (*orig_func_f_type2)(QString *, QString const&, QString const&, Qt::CaseSensitivity);
typedef QString& (*orig_func_f_type3)(QString * ,const QString * before, const QString* after, Qt::CaseSensitivity cs);
typedef QString (*orig_func_f_type)(const QKeySequence *, QKeySequence::SequenceFormat format);
static const int kShiftUnicode = 0x21E7;
static const int kOptionUnicode = 0x2325;
static const int kCommandUnicode = 0x2318;
#define my_replace_char(b,a) do { \
		QString before= orig_func_t("QShortcut",b,0,1);\
		QString after = QString(QChar(a));\
		orig_func3(&result,&before,&after,Qt::CaseInsensitive);\
} while(0);


QString QKeySequence::toString(SequenceFormat format) const {
Dl_info *info = (Dl_info*)malloc(sizeof(Dl_info));
    orig_func_f_type orig_func;
void *ap = dlsym(RTLD_NEXT, "_ZNK12QKeySequence8toStringENS_14SequenceFormatE");
dladdr(ap,info);
    orig_func = (orig_func_f_type)ap;
    // The key sequence is wanted in a "portable" format,
    // suitable for reading and writing to a file.
    // Do not rewrite this.
        QString result =  orig_func(this,format);
    if (format == 1) {
        return(result);
    }
        orig_func_f_type3 orig_func3;
        orig_func3 = (orig_func_f_type3)dlsym(RTLD_DEFAULT,"_ZN7QString7replaceERKS_S1_N2Qt15CaseSensitivityE");
        if(strstr(info->dli_fname,"/qt6/"))  {

}else {
}


orig_func_f_translate orig_func_t;
		orig_func_t =(orig_func_f_translate) dlsym(RTLD_DEFAULT,"_ZN16QCoreApplication9translateEPKcS1_S1_i");
		my_replace_char("Esc",0x238B);
		my_replace_char("Tab",0x21E5);
		my_replace_char("Backtab",0x21E4);
		my_replace_char("Backspace",0x232B);
		my_replace_char("Return",0x21B5);
		my_replace_char("Enter",0x2324);
		my_replace_char("Del",0x2326);
		my_replace_char("Home",0x2196);
		my_replace_char("End",0x2198);
		my_replace_char("Left",0x2190);
		my_replace_char("Up",0x2191);
		my_replace_char("Right",0x2192);
		my_replace_char("Down",0x2193);
		my_replace_char("PgUp",0x21DE);
		my_replace_char("PgDown",0x21DF);
		my_replace_char("Shift",kShiftUnicode);
		my_replace_char("Ctrl",kCommandUnicode);
		my_replace_char("Meta",kOptionUnicode);
		my_replace_char("CapsLock",0x21EA);
		QString before= orig_func_t("QShortCut","Alt",0,0);
		QString after= orig_func_t("QShortCut","Ctrl",0,0);
		orig_func3(&result,&before,&after,Qt::CaseInsensitive);
		return result;

}

void QArrayData::deallocate(QArrayData *data, qsizetype objectSize,
        qsizetype alignment) noexcept
{
    // Alignment is a power of two
    Q_ASSERT(alignment >= qsizetype(alignof(QArrayData))
            && !(alignment & (alignment - 1)));
    Q_UNUSED(objectSize);
    Q_UNUSED(alignment);
    ::free(
data);
}
