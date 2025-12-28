#include <QString>

class StringOperations {
public:
    // Возвращает строку в обратном порядке
    static QString reverse(const QString& str);
    
    // Подсчитывает количество вхождений символа в строку
    static int countChar(const QString& str, QChar ch);
    
    // Проверяет, содержит ли строка только цифры
    static bool isNumeric(const QString& str);
    
    // Удаляет все пробелы из строки
    static QString removeSpaces(const QString& str);
};
