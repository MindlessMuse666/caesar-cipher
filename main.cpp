#include <iostream>
#include <string>

using namespace std;

int findIndex(const string (&alphabet)[33], const string& str_char) {
    for (int i = 0; i < 33; ++i)
        if (str_char == string(alphabet[i].begin(), alphabet[i].end()))
            return i;

    return -1;
}

// Функция для шифрования/дешифрования символа
char caesarChar(char c, int key, const string (&alphabet)[33]) {
    bool isUpper = iswupper(c);
    string lowerChar = string(1, tolower(c));

    int index = findIndex(alphabet, lowerChar);

    if (index != -1) {
        int encryptedIndex = (index + key) % 33;
        string encryptedString = string(alphabet[encryptedIndex].begin(), alphabet[encryptedIndex].end());
        char encryptedChar = encryptedString[0];

        if (isUpper)
            encryptedChar = toupper(encryptedChar);
        
        return encryptedChar;
    }
    return c;
}


int main() {
    setlocale(0, "");

    string encryptedText = "";
    string alphabet_arr[33] = {
        "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о",
        "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"
    };

    cout << "Введите строку для шифрования: ";
    string userInput; cin >> userInput;

    cout << "Введите ключ сдвига: ";
    int key; cin >> key;

    for (char c : userInput)
        encryptedText += caesarChar(c, key, alphabet_arr);

    cout << "Зашифрованный текст: " << encryptedText << endl;

    string decryptedText = "";
    for (char c : encryptedText)
        decryptedText += caesarChar(c, -key, alphabet_arr);

    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}