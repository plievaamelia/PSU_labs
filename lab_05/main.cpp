#include "func.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int choice;

    do {
        cout << "ËÀÁÎÐÀÒÎÐÍÀß ÐÀÁÎÒÀ 5" << endl;
        cout << "1 - String53 " << endl;
        cout << "2 - Str16 " << endl;
        cout << "3 - Str23 " << endl;
        cout << "4 - Str36 " << endl;
        cout << "5 - Str28 " << endl;
        cout << "6 - task1 " << endl;
        cout << "7 - five3 " << endl;
        cout << "0 - Âûõîä" << endl;
        cout << "Âàø âûáîð: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
        case 1:
            string53();
            break;
        case 2:
            str16();
            break;
        case 3:
            str23();
            break;
        case 4:
            str36();
            break;
        case 5:
            str28();
            break;
        case 6:
            task6_1();
            break;
        case 7:
            five3();
            break;
        case 0:
            cout << "Âûõîä èç ïðîãðàììû..." << endl;
            cout << "Óñïåøíî." << endl;
            break;
        default:
            cout << "Îøèáêà: íåâåðíûé âûáîð!" << endl;
            break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}