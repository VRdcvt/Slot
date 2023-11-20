#include <iostream>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void setcur(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
BOOL ShowConsoleCursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if (!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if (!SetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    return TRUE;
}

char step1(vector<char> vec1, vector<char> vec2, vector<char> vec3) {
    char sym1;
    system_clock::time_point end = system_clock::now()+1s;
    for (size_t i = 0;; i++)
    {
        cout << "   ___________________" << endl;
        cout << "  /                  /|" << endl;
        cout << " /__________________/ |" << endl;
        cout << "|    ___ ___ ___    | | " << char(79) << endl;
        cout << "|   |   |   |   |   | | " << char(186) << endl;
        cout << "|   | " << vec1[rand() % 5] << " | " << vec2[rand() % 5] << " | " << vec3[rand() % 5] << " |   | | " << char(186) << endl;
        cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
        cout << "|                   | |" << endl;
        cout << "|                   | /" << endl;
        cout << "|___________________|/" << endl;
        setcur(0, 0);
        if (system_clock::now() >= end) {
            sym1 = vec1[rand() % 5];
            return sym1;
        }
    }
}
char step2(char sym, vector<char> vec2, vector<char> vec3) {
    char sym1;
    system_clock::time_point end = system_clock::now() + 1s;
    for (size_t i = 0;; i++)
    {
        cout << "   ___________________" << endl;
        cout << "  /                  /|" << endl;
        cout << " /__________________/ |" << endl;
        cout << "|    ___ ___ ___    | | " << char(79) << endl;
        cout << "|   |   |   |   |   | | " << char(186) << endl;
        cout << "|   | " << sym << " | " << vec2[rand() % 5] << " | " << vec3[rand() % 5] << " |   | | " << char(186) << endl;
        cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
        cout << "|                   | |" << endl;
        cout << "|                   | /" << endl;
        cout << "|___________________|/" << endl;
        setcur(0, 0);
        if (system_clock::now() >= end) {
            sym1 = vec2[rand() % 5];
            return sym1;
        }
    }
}
char step3(char sym, char sym2, vector<char> vec3) {
    char sym1;
    system_clock::time_point end = system_clock::now() + 1s;
    for (size_t i = 0;; i++)
    {
        cout << "   ___________________" << endl;
        cout << "  /                  /|" << endl;
        cout << " /__________________/ |" << endl;
        cout << "|    ___ ___ ___    | | " << char(79) << endl;
        cout << "|   |   |   |   |   | | " << char(186) << endl;
        cout << "|   | " << sym << " | " << sym2 << " | " << vec3[rand() % 5] << " |   | | " << char(186) << endl;
        cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
        cout << "|                   | |" << endl;
        cout << "|                   | /" << endl;
        cout << "|___________________|/" << endl;
        setcur(0, 0);
        if (system_clock::now() >= end) {
            sym1 = vec3[rand() % 5];
            return sym1;
        }
    }
}
int end(int credits,char sym, char sym2, char sym3) {

        cout << "   ___________________" << endl;
        cout << "  /                  /|" << endl;
        cout << " /__________________/ |" << endl;
        cout << "|    ___ ___ ___    | | " << char(79) << endl;
        cout << "|   |   |   |   |   | | " << char(186) << endl;
        cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
        cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
        cout << "|                   | |" << endl;
        cout << "|                   | /" << endl;
        cout << "|___________________|/" << endl;
        if (sym == char(55) && sym2 == char(55) && sym3 == char(55)) {
            credits += 100000;
            cout << "Jack pot! YOU WIN 100000! Your credit balance is: " << credits << " now.";
            return credits;
        }
        else if (sym == char(36) && sym2 == char(36) && sym3 == char(36)) {
            credits += 30000;
            cout << "YOU WIN 30000! Your credit balance is: " << credits << " now.";
            return credits;
        }
        else if (sym == char(14) && sym2 == char(14) && sym3 == char(14)) {
            credits += 10000;
            cout << "YOU WIN 10000! Your credit balance is: " << credits << " now.";
            return credits;
        }
        else if (sym == char(3) && sym2 == char(3) && sym3 == char(3)) {
            credits += 5000;
            cout << "YOU WIN 5000! Your credit balance is: " << credits << " now.";
            return credits;
        }
        else if (sym == char(15) && sym2 == char(15) && sym3 == char(15)) {
            credits += 1000;
            cout << "YOU WIN 1000! Your credit balance is: " << credits << " now.";
            return credits;
        }
        else
        {
            credits -= 100;
            cout << "good luck next time! Your credit balance is: " << credits << " now.";
            return credits;
        }
}

void start(char sym, char sym2, char sym3) {
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << char(79) << endl;
    cout << "|   |   |   |   |   | | " << char(186) << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    cout << "\npress SPACE for play, or ANOTHER BUTTON for exit" << endl;
}
void push(char sym, char sym2, char sym3) {
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << char(79) << endl;
    cout << "|   |   |   |   |   | | " << char(186) << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << endl;
    cout << "|   |   |   |   |   | | " << char(79) << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << endl;
    cout << "|   |   |   |   |   | | " << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(79) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << endl;
    cout << "|   |   |   |   |   | | " << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(79) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << endl;
    cout << "|   |   |   |   |   | | " << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(79) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << endl;
    cout << "|   |   |   |   |   | | " << char(79) << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    Sleep(50);
    system("cls");
    cout << "   ___________________" << endl;
    cout << "  /                  /|" << endl;
    cout << " /__________________/ |" << endl;
    cout << "|    ___ ___ ___    | | " << char(79) << endl;
    cout << "|   |   |   |   |   | | " << char(186) << endl;
    cout << "|   | " << sym << " | " << sym2 << " | " << sym3 << " |   | | " << char(186) << endl;
    cout << "|   |___|___|___|   | " << char(205) << char(205) << char(188) << endl;
    cout << "|                   | |" << endl;
    cout << "|                   | /" << endl;
    cout << "|___________________|/" << endl;
    system("cls");
}

int main()
{
    srand(time(NULL));
    vector<char> line1{ char(15), char(3),char(14),char(36),'7' };
    vector<char> line2{ char(15), char(3),char(14),char(36),'7' };
    vector<char> line3{ char(15), char(3),char(14),char(36),'7' };
    char sym1=' ', sym2=' ', sym3=' ';
    int credits;
    do {
        cout << "enter the count of your credit: ";
        cin >> credits;
        if (credits < 100)
            cout << "Cost of 1 game is 100 credits.\n";
    } while (credits < 100);
    ShowConsoleCursor(FALSE);
    start(sym1, sym2, sym3);
    if (_getch() == 32)
        push(sym1, sym2, sym3);
    else
        exit(1);
    do
    {
        sym1 = step1(line1, line2, line3);
        sym2 = step2(sym1, line2, line3);
        sym3 = step3(sym1, sym2, line3);
        credits = end(credits,sym1, sym2, sym3);
        if (_getch() == 32)
            push(sym1, sym2, sym3);
        else
            exit(1);
    }while (credits>=100);
    cout << "Game over!";
}

