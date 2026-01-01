#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "func.h"

using namespace std;

//способ ввода
string input(string random) {
    int choice;
    cout << "выберете способ ввода строки: "<<endl;
    cout << "1. вручную с консоли" << endl;
    cout << "2. из файла" << endl;
    cout << "3. автоматический ввод на рандом" << endl;
    cout << "ваш выбор: " << endl;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "ошибка! введите 1, 2 или 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    cout << endl;
    string text = "";
    ifstream file("text.txt");
    int len = rand() % 30 + 10;
    switch (choice) {
    case 1:
        cout << "введите строку: ";
        getline(cin, text);
        break;
    case 2:
        if (!file.is_open()) {
            cout << "ошибка открытия файла " << endl;
        }
        else {
            getline(file, text);
            file.close();
        }
        break;

    case 3:
        for (int i = 0; i < len; i++) {
            text += random[rand() % random.length()];
        }
        cout << "сгенерированная строка: " << text<<endl;
        break;
    default:
        break;
    }
    return text;
}




//string53

bool punct(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':' || c == '-' || c == '(' || c == ')' || c == '\"' || c == '\'';
}

string countpunct(const string& input) {
    int count = 0;
    for (char c : input) {
        if (punct(c)) {
            count++;
        }
    }
    return "Количество знаков препинания: " + to_string(count);
}









//str23

//'H' = ASCII 72
//Двоичный вид : 01001000
//
//Гамма = 200
//Двоичный вид : 11001000
//
//XOR операция :
//01001000 (72)
//11001000 (200)
//--------
//10000000 (128) = символ 'x'

string xor_crypt(const string& input, int gamma) {
    string result = input;
    for (int i = 0; i < result.length(); i++) {
        result[i] = result[i] ^ gamma; // ^ - это оператор XOR
    }
    return result;
}

















//str28



// Функция для преобразования символа в числовое значение
int chartovalue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
}

//'0' - '0' = 0     '0' имеет код 48, 48 - 48 = 0
//'1' - '0' = 1     '1' имеет код 49, 49 - 48 = 1
// 
//'9' - '0' = 9     '9' имеет код 57, 57 - 48 = 9

//'A' - 'A' + 10 = 0 + 10 = 10
//'B' - 'A' + 10 = 11 - 10 + 10 = 11
//
//'a' - 'a' + 10 = 0 + 10 = 10
//'b' - 'a' + 10 = 1 + 10 = 11



// числовоe значениe в символ
char valuetochar(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value;                // value = 7; 48 + 7 = 55; '7' = ASCII 55
    }
    else if (value >= 10 && value <= 35) {
        return 'A' + (value - 10);         // value = 11; 65 + (11 - 10) = 66; 'B' = ASCII 66
    }
}



// из p-ричной в q-ричную систему
string convertBase(const string& number, int p, int q) {
    bool isneg = false;
    string num = number;
    if (num[0] == '-') {
        isneg = true;
        num = num.substr(1); 
    }

    // из p-ричной в десятичную систему
    long long value10 = 0;
    int len = num.length();
    for (int i = 0; i < len; i++) {
        char c = num[i];
        int value = chartovalue(c);
        int ind = len - 1 - i; 
        long long stepen = pow(p, ind); 
        value10 += value * stepen;
    }

    if (value10 == 0) {
        return "0";
    }

    // из десятичной в q-ричную систему
    string result = "";
    long long temp = value10;

    while (temp > 0) {
        int remainder = temp % q;
        result = valuetochar(remainder) + result;
        temp /= q;
    }

    if (isneg) {
        result = "-" + result;
    }

    return result;
}
    


