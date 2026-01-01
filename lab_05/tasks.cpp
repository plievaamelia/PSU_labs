#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "func.h"

using namespace std;


//string53 ƒана строка-предложение на русском €зыке. ѕодсчитать количество содержащихс€ 
//         в строке знаков препинани€.
void string53() {
    string random = "0123456789 .,!?абвгдеЄжзийклмнопрстуфхцчшщъыьэю€јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
    string text = input(random);
    int cont = 1;
    int s = 0;
    for (char c : text) {
        if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            cont = 0;
        }
        s += c;
    }
    if (cont == 1 && s != 0) {
        string result = countpunct(text);
        cout << "результат: " << result << endl;
    }
    else {
        cout << "в строке не русские символы или строка пуста€" << endl;
    }

}







//str16 ƒана строка. ѕреобразуйте ее следующим образом: 
//      каждый пробел замените символом с ASCII - кодом 35,
//      а в конце строки поставьте символ с ASCII - кодом 33.
void str16() {
    string random = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?абвгдеЄжзийклмнопрстуфхцчшщъыьэю€јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
    string text = input(random);
    int s = 0;
    for (char c : text) {
        s += c;
    }
    if (s != 0) {
        string result = text;
        for (char& c : result) {
            if (c == ' ') {
                c = 35;
            }
        }

        result += 33;

        cout << "исходна€ строка:        " << text << endl;
        cout << "преобразованна€ строка: " << result << endl;
    }
    else {
        cout << "строка пуста" << endl;
    }

    // пробелы заменены на '#' (ASCII 35)
    // в конец добавлен '!' (ASCII 33)
}






//str23 ƒана строка. –еализовать метод шифрации "Ќаложение гаммы". "новый код=старый код XOR гамма".
//      √амма находитс€ в диапазоне от 127 до 255 –асшифровать строку при заданной гамме.
void str23() {
    string random = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?абвгдеЄжзийклмнопрстуфхцчшщъыьэю€јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
    string text = input(random);
    int gamma;
    cout << "введите гамму: ";
    cin >> gamma;
    cout << "шифровка: " << xor_crypt(text, gamma) << endl;
    cout << "расшифровка: " << xor_crypt(xor_crypt(text, gamma), gamma) << endl;
}
//'H' = ASCII 72
//ƒвоичный вид : 01001000
//
//√амма = 200
//ƒвоичный вид : 11001000
//
//XOR операци€ :
//01001000 (72)
//11001000 (200)
//--------
//10000000 (128) = символ 'x'

 



//str36 ƒана строка. ѕодсчитать, сколько различных символов встречаетс€ в ней. ¬ывести их на экран.
//      «наки препинани€ не считать. Ѕуквы в разных регистрах считать различными символами.
//      () - это тоже знаки препинани€
void str36() {
    string random = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?абвгдеЄжзийклмнопрстуфхцчшщъыьэю€јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";
    string text = input(random);
    int cnt = 0;
    string uniq = "";
    for (int i = 0; i < text.length();i++) {
        char cur = text[i];
        if (punct(cur)) {
            continue;
        }
        int control = 0;
        for (int j = 0; j < uniq.length(); j++) {
            if (uniq[j] == cur) {
                control = 1;
                break;
            }
        }
        if (control == 0) {
            uniq = uniq + cur;
            cnt++;
        }
    }
    if (cnt > 0) {
        cout << "различных символов: " << cnt << endl;
        cout << "уникальные символы: ";
        for (int i = 0; i < uniq.length(); i++) {
            cout << " " << uniq[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "уникальных символов не найдено или ваша строка пуста"<<endl;
    }
}





//str28 ƒано шестнадцатеричное число, в котором буквенные обозначени€ цифр могут быть записаны как заглавными,
//      так и строчными символами. ѕеревести это число в 8 - ю систему счислени€.

void str28() {
    string random = "ABCDEFabcdef0123456789";
    string number = input(random);
    int cont = 1;
    int s = 0;
    for (char c : number) {
        if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || c == 45 || (c >= 97 && c <= 102))) {
            cont = 0;
        }
        s += c;
    }
    if (cont == 1 && s != 45 && s != 0) {
        string result = convertBase(number, 16, 8);
        cout << "результат: " << result << endl;
    }
    else if (s == 45 || s == 0) {
        cout << "число не может состо€ть лишь из знака или пустой строки!" << endl;
    }
    else {
        cout << "ошибка: в строке есть посторонние символы!" << endl;
    }
}








//1.  Ќапишите генератор паролей.—оставьте три уровн€ сложности генерации паролей(вместе
//    с их длиной) и спрашивайте у пользовател€, какой уровень сложности ему нужен.ѕро€вите свою
//    изобретательность : надЄжные пароли должны состо€ть из сочетани€ строчных букв, прописных
//    букв, цифр и символов.ѕароли должны генерироватьс€ случайным образом каждый раз, когда
//    пользователь запрашивает новый пароль.
void task6_1() {
    int level_choice;
    do {
        cout << "выберете уровень сложности: " << endl;
        cout << "1 - простой (6 символов, буквы)" << endl;
        cout << "2 - средний (8 символов, буквы и цифры)" << endl;
        cout << "3 - сложный (12 символов, буквы, цифры и спецсимволы)" << endl;
        cout << "0 - выйти из генератора паролей" << endl;
        cout << "ваш выбор: ";
        if (!(cin >> level_choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            level_choice = 4;
        }
        string lower = "abcdefghijklmnopqrstuvwxyz";
        string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string digits = "0123456789";
        string simbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
        string password, base;
        switch (level_choice) {
        case 1:
            password = "";
            base = lower + upper;
            for (int i = 0; i < 6; i++) {
                password += base[rand() % base.length()];
            }
            cout << "сгенерированный пароль: " << password << endl;
            break;
        case 2:
            password = "";
            base = lower + upper + digits;
            for (int i = 0; i < 8; i++) {
                password += base[rand() % base.length()];
            }
            cout << "сгенерированный пароль: " << password << endl;
            break;
        case 3:
            password = "";
            base = lower + upper + digits + simbols;
            for (int i = 0; i < 12; i++) {
                password += base[rand() % base.length()];
            }
            cout << "сгенерированный пароль: " << password << endl;
            break;
        case 0:
            cout << "выход из генератора" << endl;
            break;
        default:
            cout << "неверный выбор" << endl;
            break;
        }

    } while (level_choice != 0);
}




//five3 ¬ текстовом файле c именем FN1 даны примеры домашней работы второклассника в фор -
//      мате: <операнд><знак>< операнд >= ќперанды €вл€ютс€ не более, чем трехзначными натураль -
//      ными числами, в качестве знаков операций используютс€ '+' и '-'.Ќужно решить домашнюю ра -
//      боту второклассника, записав эти же примеры в выходной файл с именем FN2, указыва€ после
//      знака '=' ответы.
void five3() {
    ifstream f1;
    ofstream f2;
    f1.open("FN1.txt", ios::in);
    f2.open("FN2.txt", ios::out);
    if (!f1.is_open()) {
        cout << "файл FN1 не получилось открыть" << endl;
    }
    string line;
    while (getline(f1, line)) {
        string resline = "";
        if (line.empty()) {
            f2 << resline << endl;
            continue;
        }
        else {
            // пропуск пробелов
            for (int i = 0; i < line.length();i++) {
                if (line[i] != ' ') {
                    resline += line[i];
                }
            }
            // проверка на корректность
            int cont = 0;
            for (char c : resline) {
                if ((c < 48 || c > 57) && c != '+' && c != '-' && c != '=') {
                    f2 << "в строке есть посторонние символы!" << endl;
                    cont = 1;
                    break;
                }
            }
            if (cont != 1) {
                int cnt1 = 0;
                int cnt2 = 0;
                int s = 0;
                for (char c : resline) {
                    if (cnt1 == 0 && (c == '+' || c == '-')) {
                        cnt1++;
                    }
                    else if (cnt1 == 1 && c == '=') {
                        cnt2++;
                    }
                    s += c;
                }
                if (cnt1 != 1 || cnt2 || 1 || cnt1 != cnt2 || s == 104 || s == 106) {
                    f2 << "строка должна иметь вид <операнд><знак(+ или -)><операнд> = " << endl;
                }
                else {
                    string n1str = "";
                    int i = 0;
                    while (i < resline.length() && resline[i] >= '0' && resline[i] <= '9') { // '' - char, "" - string
                        n1str += resline[i];
                        i++;
                    }
                    char op = '?';
                    if (i < resline.length() && (resline[i] == '+' || resline[i] == '-')) {
                        op = resline[i];
                        i++;
                    }
                    string n2str = "";
                    while (i < resline.length() && resline[i] >= '0' && resline[i] <= '9') {
                        n2str += resline[i];
                        i++;
                    }
                    int n1 = 0;
                    for (int j = 0; j < n1str.length(); j++) {//                         50 - 48
                        n1 = n1 * 10 + (n1str[j] - '0'); // n1str = '2' тогда 0 * 10 + ('2' - '0') = 0 * 10 + 2 = 2
                    }
                    int n2 = 0;
                    for (int j = 0; j < n2str.length(); j++) {
                        n2 = n2 * 10 + (n2str[j] - '0');
                    }
                    int res = 0;
                    if (op == '+') {
                        res = n1 + n2;
                    }
                    else if (op == '-') {
                        res = n1 - n2;
                    }
                    else {
                        res = 99999999;
                    }
                    f2 << resline << res << endl;
                }
            }

        }
    }
   
    cout << "завершено успешно";
    f1.close();
    f2.close();

}