
//В шифре Цезаря алфавит размещается на круге по часовой стрелке. За последней буквой алфавита идет первая буква алфавита, 
// т.е. после буквы “я” идет буква “а”. При шифровании текста буквы заменяются другими буквами, отстоящими по кругу на 
// заданное количество позиций (сдвиг) дальше по часовой стрелке. Например, если сдвиг равен 3, то буква “а” заменяется 
// на букву “г”, буква “б” на букву “д”, а буква “я” на букву “в”.
//Зашифровать сообщение, используя шифр Цезаря со сдвигом k.
//Например, дан алфавит{ a, b, c } с помощью которого записано слово abaccc.Используя шифр Цезаря со сдвигом 2, 
// мы получим слово cacbbb.

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void EnglishEncryption(int k, string file)
{
    ifstream reading(file);
    cout << "Текст для шифрования:" << endl;
    string line; // строка для считывания данных из файла
    while (getline(reading, line)) { // чтение строк из файла
        cout << line << endl << endl; // вывод строки на экран
    }
    reading.close();


    ifstream input(file);
    int i = 0;
    cout << "Зашифрованный текст:" << endl;
    while (getline(input, line)) { // чтение строк из файла
        while (i < line.length())
        {
            char c = line[i];

            if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
            {
                char b2 = (int)c + k;
                if ((int)b2 > 90 && (int)c < 91)
                {
                    b2 = (int)b2 - 90;
                    b2 = (int)b2 + 64;
                }
                if ((int)b2 > 122 && (int)c > 96)
                {
                    b2 = (int)b2 - 122;
                    b2 = (int)b2 + 96;
                }
                cout << b2;
            }
            else
            {
                cout << c;
            }
            i++;
        }
    }
    input.close();
}

void EnglishDecoding(int k, string file)
{
    ifstream reading(file);
    cout << "Текст для расшифровывания:" << endl;
    string line; // строка для считывания данных из файла
    while (getline(reading, line)) { // чтение строк из файла
        cout << line << endl << endl; // вывод строки на экран
    }
    reading.close();


    ifstream input(file);
    int i = 0;
    cout << "Расшифрованный текст:" << endl;
    while (getline(input, line)) { // чтение строк из файла
        while (i < line.length())
        {
            char c = line[i];

            if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
            {
                char b2 = (int)c - k;
                if ((int)b2 < 65 && (int)c < 91)
                {
                    b2 = (int)b2 + 26;
                }
                if ((int)b2 < 97 && (int)c > 96)
                {
                    b2 = (int)b2 + 26;
                }
                cout << b2;
            }
            else
            {
                cout << c;
            }
            i++;
        }
        cout << endl;
    }
    input.close();
}

int Shift_digit()
{
    string k_str;
    int k;

    while (true)
    {
        cout << "Введите цифру сдвига в пределах от 0 до 25: ";
        getline(cin, k_str);

        bool is_all_digits = true;
        for (char c : k_str)
        {
            if (!isdigit(c))
            {
                is_all_digits = false;
                break;
            }
        }

        if (is_all_digits)
        {
            k = stoi(k_str);
            if ((k >= 0) && (k <= 25))
            {
                return k;
                break;
            }
        }

        cout << "Введено некорректное число" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");



    int cipher;
    while (true)
    {
        cout << "Для шифровки текста введите - 1" << endl << "Для расшифровки текста введите - 2" << endl;
        cout << "Выбор: ";
        cin >> cipher;
        if (cipher == 1 || cipher == 2)
        {
            break;
        }
        else
        {
            cout << "Введено некорректное число" << endl;
        }
    }

    cin.ignore();

    string file;
    while (true)
    {
        cout << "Введите название файла: ";
        getline(cin, file);
        ifstream input(file);
        if (input.is_open())
        {
            int k = Shift_digit();

            if (cipher == 1)
            {
                EnglishEncryption(k, file);
            }
            else if (cipher == 2)
            {
                EnglishDecoding(k, file);
            }
            break;
        }
        else
        {
            cout << "Ошибка открытия файла" << endl;
        }
    }


}


//65-90 - A Z
//97-122 - a z

