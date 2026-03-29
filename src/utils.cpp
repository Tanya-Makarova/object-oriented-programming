#include "utils.h"


int safeReadInt()
{
    int value;
    while (true) 
    {
        cin >> value;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите целое число: ";
        } else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
double safeReadDouble() 
{
    double value;
    while (true) 
    {
        cin >> value;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите число: ";
        } else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
string safeReadLine() 
{
    string line;
    getline(cin >> ws, line);
    while (line.empty()) {
        cout << "Строка не может быть пустой. Повторите ввод: ";
        getline(cin >> ws, line);
    }
    return line;
}
void clearScreen()
{
    #ifdef _WIN32
        system("cls"); // Вызывваем системную команду виндоус для очиски экрана меню, чтобы не захламлять
    #endif
}
void waitForEnter()
{
    cout << "Нажмите Enter для продолжения ";
    cin.get();
}
