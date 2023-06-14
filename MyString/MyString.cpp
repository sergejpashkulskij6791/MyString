#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    int size;

public:
    // Конструктор по умолчанию
    MyString() {
        size = 80;
        str = new char[size + 1]; // +1 для символа '\0' в конце строки
    }

    // Конструктор для создания строки произвольного размера
    MyString(int length) {
        size = length;
        str = new char[size + 1];
    }

    // Конструктор, который инициализирует строку значением, полученным от пользователя
    MyString(const char* inputStr) {
        size = strlen(inputStr);
        str = new char[size + 1];
        strcpy_s(str,size, inputStr);
       // strcpy(str, inputStr);
    }

    // Конструктор копирования
    MyString(const MyString& other) {
        size = other.size;
        str = new char[size + 1];
        strcpy_s(str, size, other.str);
    }

    // Метод для ввода строки с клавиатуры
    void InputString() {
        std::cout << "Введите строку: ";
        std::cin.getline(str, size + 1);
    }

    // Метод для вывода строки на экран
    void OutputString() const {
        std::cout << "Строка: " << str << std::endl;
    }

    // Метод для получения длины строки
    int Length() const {
        return strlen(str);
    }

    // Метод для проверки, начинается ли строка с заданного символа
    bool StartsWith(char ch) const {
        return str[0] == ch;
    }

    // Метод для проверки, заканчивается ли строка заданным символом
    bool EndsWith(char ch) const {
        int len = strlen(str);
        return len > 0 && str[len - 1] == ch;
    }

    // Метод для сравнения строки с заданной C-строкой
    bool Equal(const char* otherStr) const {
        return strcmp(str, otherStr) == 0;
    }

    // Метод для получения указателя на строку
    const char* GetStr() const {
        return str;
    }

    // Метод для установки значения строки
    void SetStr(const char* newStr) {
        delete[] str; // Освобождаем старую память
        size = strlen(newStr);
        str = new char[size + 1];
        strcpy_s(str, size, newStr);
    }

    // Деструктор
    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString s1; // Создание строки длиной 80 символов
    s1.InputString(); // Ввод строки с клавиатуры
    s1.OutputString(); // Вывод строки на экран

    MyString s2(50); // Создание строки длиной 50 символов
    s2.InputString();
    s2.OutputString();

    MyString s3("Hello"); // Создание строки и инициализация значением
    s3.OutputString();

    MyString s4(s3); // Создание строки на основе существующей строки
    s4.OutputString();

    std::cout << "Длина строки s4: " << s4.Length() << std::endl;
    std::cout << "Строка s4 начинается с символа 'H': " << s4.StartsWith('H') << std::endl;
    std::cout << "Строка s4 заканчивается символом 'o': " << s4.EndsWith('o') << std::endl;
    std::cout << "Строка s4 равна \"Hello\": " << s4.Equal("Hello") << std::endl;

    const char* strPtr = s4.GetStr(); // Получение указателя на строку
    std::cout << "Указатель на строку s4: " << strPtr << std::endl;

    s4.SetStr("New String"); // Изменение значения строки
    s4.OutputString();

    return 0;
}
