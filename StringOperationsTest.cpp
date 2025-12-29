#ifndef STRINGOPERATIONSTEST_H
#define STRINGOPERATIONSTEST_H

#include <QTest>
#include <QDebug>
#include <QRegularExpression>
#include "StringOperation/StringOperations.h"

class TestStringOperations : public QObject
{
    Q_OBJECT

private slots:
    // Тесты для reverse()
    void testReverse_data();
    void testReverse();

    // Тесты для countChar()
    void testCountChar_data();
    void testCountChar();

    // Тесты для isNumeric()
    void testIsNumeric_data();
    void testIsNumeric();

    // Тесты для removeSpaces()
    void testRemoveSpaces_data();
    void testRemoveSpaces();
};

void TestStringOperations::testReverse_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("expected");

    QTest::newRow("simple") << "Hello" << "olleH";
    QTest::newRow("numbers") << "12345" << "54321";
    QTest::newRow("spaces") << "a b c" << "c b a";
    QTest::newRow("mixed") << "a1b2c3" << "3c2b1a";
    QTest::newRow("empty") << "" << "";
    QTest::newRow("single") << "a" << "a";
}

void TestStringOperations::testReverse()
{
    QFETCH(QString, input);
    QFETCH(QString, expected);

    QString result = StringOperations::reverse(input);
    QCOMPARE(result, expected);
}

void TestStringOperations::testCountChar_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QChar>("character");
    QTest::addColumn<int>("expected");

    QTest::newRow("basic") << "hello" << QChar('l') << 2;
    QTest::newRow("none") << "hello" << QChar('z') << 0;
    QTest::newRow("all") << "aaaa" << QChar('a') << 4;
    QTest::newRow("spaces") << "a a a" << QChar('a') << 3;
    QTest::newRow("empty") << "" << QChar('a') << 0;
    QTest::newRow("case sensitive") << "Hello hello" << QChar('h') << 1;
    QTest::newRow("number") << "123121" << QChar('1') << 3;
}

void TestStringOperations::testCountChar()
{
    QFETCH(QString, input);
    QFETCH(QChar, character);
    QFETCH(int, expected);

    int result = StringOperations::countChar(input, character);
    QCOMPARE(result, expected);
}

void TestStringOperations::testIsNumeric_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<bool>("expected");

    QTest::newRow("valid number") << "12345" << true;
    QTest::newRow("zero") << "0" << true;
    QTest::newRow("negative") << "-123" << false; // Наш метод не поддерживает отрицательные
    QTest::newRow("decimal") << "123.45" << false;
    QTest::newRow("with letters") << "12a45" << false;
    QTest::newRow("empty") << "" << false;
    QTest::newRow("spaces") << " 123 " << false;
    QTest::newRow("only letters") << "abc" << false;
    QTest::newRow("hex") << "0xFF" << false;
    QTest::newRow("big number") << "999999999" << true;
}

void TestStringOperations::testIsNumeric()
{
    QFETCH(QString, input);
    QFETCH(bool, expected);

    bool result = StringOperations::isNumeric(input);
    QCOMPARE(result, expected);
}

void TestStringOperations::testRemoveSpaces_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("expected");

    QTest::newRow("simple") << "a b c" << "abc";
    QTest::newRow("leading spaces") << "  hello" << "hello";
    QTest::newRow("trailing spaces") << "hello  " << "hello";
    QTest::newRow("multiple spaces") << "a    b    c" << "abc";
    QTest::newRow("tabs and spaces") << "a\tb\nc" << "abc";
    QTest::newRow("empty") << "" << "";
    QTest::newRow("only spaces") << "   " << "";
    QTest::newRow("no spaces") << "hello" << "hello";
    QTest::newRow("unicode with spaces") << "при вет мир" << "приветмир";
}

void TestStringOperations::testRemoveSpaces()
{
    QFETCH(QString, input);
    QFETCH(QString, expected);

    QString result = StringOperations::removeSpaces(input);
    QCOMPARE(result, expected);
}

#endif // STRINGOPERATIONSTEST_H
