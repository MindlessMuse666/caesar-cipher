#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <algorithm>


// Функция для корректной настройки консоли (локаль, кодировка)
void setupConsole() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, ".1251");
}

// Функция для очистки консоли
void clearConsole() {
    system("cls");
}

// Функция для шифрования/дешифрования символа
char caesarCipher(char ch, int key, int language) {
    
    // Английский
    if (language == 1) {
        if (ch >= 'a' && ch <= 'z') {
            int base = 'a';
            return (char)((((ch - base) + key) % 26 + 26) % 26 + base);
        }
        if (ch >= 'A' && ch <= 'Z') {
            int base = 'A';
            return (char)((((ch - base) + key) % 26 + 26) % 26 + base);
        }
    }

    // Русский
    else if (language == 2) {
        if (ch >= 'а' && ch <= 'я') {
            int base = 'а';
            return (char)((((ch - base) + key) % 32 + 32) % 32 + base);
        }
        if (ch >= 'А' && ch <= 'Я') {
            int base = 'А';
            return (char)((((ch - base) + key) % 32 + 32) % 32 + base);
        }
    }

    return ch; // Возвращаем символ без изменений, если он не в диапазоне
}

// Функция для обработки строки
std::string processString(const std::string& text, int key, int language) {
    std::string result = text;

    std::transform(result.begin(), result.end(), result.begin(),
        [&](char ch) { return caesarCipher(ch, key, language); });

    return result;
}

int main() {
    // Настраиваем консоль
    setupConsole();

    // Объявляем переменные
    std::string inputText;
    int key;
    int language;

    // Инициализируем переменные
    std::cout << "Выберите язык ввода:\n1. Английский\n2. Русский\n\n";
    std::cin >> language;
    std::cin.ignore();

    std::cout << "Введите текст: ";
    std::getline(std::cin, inputText);

    std::cout << "Введите ключ: ";
    std::cin >> key;

    // Отчищаем консоль перед выводом конечного результата
    clearConsole();

    // Обработка строки и вывод результата
    std::string encryptedString = processString(inputText, key, language);
    std::cout <<
        "Начальная строка: " << inputText << "\n" <<
        "Зашифрованная строка: " << encryptedString << "\n";

    // Дожидаемся, когда пользователь введёт что-нибудь для закрытия программы
    system("pause");
    return 0;
}