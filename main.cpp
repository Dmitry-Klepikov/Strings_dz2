#include <QCoreApplication>
#include <iostream>
#include "StringOperation/StringOperations.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "=== Демонстрация операций со строками ===\n\n";

    QString testStr = "Hello World";

    qDebug() << "Исходная строка: " << testStr << "\n";

    qDebug() << "Реверс строки: " << StringOperations::reverse(testStr) << "\n";

    qDebug() << "Количество 'l' в строке '" << testStr << "': "
              << StringOperations::countChar(testStr, 'l') << "\n";

    qDebug() << "Строка '12345' состоит только из цифр? "
              << (StringOperations::isNumeric("12345") ? "Да" : "Нет") << "\n";

    qDebug() << "Строка '12a45' состоит только из цифр? "
              << (StringOperations::isNumeric("12a45") ? "Да" : "Нет") << "\n";

    qDebug() << "Без пробелов: '" << StringOperations::removeSpaces("a b c") << "'\n";

    qDebug() << "\n============================================\n";

    return a.exec();
}
