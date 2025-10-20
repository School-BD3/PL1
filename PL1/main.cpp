#define NOMINMAX
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <locale>
#include "root.h"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "");

    while (true) {
        cout << "Введіть x (Esc - вихід): ";

        string input;
        char ch;

        while (true) {
            ch = _getch();

            if (ch == 27) {
                cout << "\nВихід з програми.\n";
                return 0;
            }

            if (ch == '\r') {
                cout << endl;
                break;
            }

            if (ch == '\b') {
                if (!input.empty()) {
                    input.pop_back();
                    cout << "\b \b";
                }
                continue;
            }

            input += ch;
            cout << ch;
        }

        double x;
        {
            std::istringstream iss(input);
            iss.imbue(std::locale::classic());
            if (!(iss >> x)) {
                cout << "Невірне введення\n";
                continue;
            }
        }

        double y;
        string err;
        if (calc(x, y, err)) {
            cout << "y = " << y << endl;
        }
        else {
            cout << "Помилка: " << err << endl;
        }
    }
}
