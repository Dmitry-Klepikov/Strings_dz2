#include "StringOperations.h"
#include <algorithm>
#include <cctype>

QString StringOperations::reverse(const QString& str)
{
    QString result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

int StringOperations::countChar(const QString& str, QChar ch)
{
    return std::count(str.begin(), str.end(), ch);
}


bool StringOperations::isNumeric(const QString& str)
{
    if (str.isEmpty())
    {
        return false;
    }
    
    for (QChar c : str)
    {
        if (!c.isDigit())
        {
            return false;
        }
    }
    return true;
}

QString StringOperations::removeSpaces(const QString& str)
{
    return str.simplified().remove(' '); // удаляет все пробелы
}
