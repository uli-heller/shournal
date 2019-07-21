#include <clocale>
#include <cstring>

#include "translation.h"
#include "util.h"

static locale_t g_locale;


bool translation::init()
{
    g_locale = newlocale(LC_CTYPE_MASK|LC_NUMERIC_MASK|LC_TIME_MASK|
               LC_COLLATE_MASK|LC_MONETARY_MASK|LC_MESSAGES_MASK,
               "",locale_t(nullptr));

    return g_locale != locale_t(nullptr);
}



char *translation::strerror_l(int errorNumber)
{
    if (g_locale == locale_t(nullptr)) {
        return ::strerror(errorNumber);
    }
    return ::strerror_l(errorNumber, g_locale);
}



translation::TrSnippets* translation::TrSnippets::s_instance = nullptr;

translation::TrSnippets::TrSnippets() :
    enable(qtr("enable")),
    shournalShellIntegration(qtr("shournal shell-integration")),
    shournalRestore(qtr("shournal-restore"))
{}

translation::TrSnippets::~TrSnippets()
= default;

translation::TrSnippets& translation::TrSnippets::instance()
{
    static TrSnippets s_instance;
    return s_instance;
}
