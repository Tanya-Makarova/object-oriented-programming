#include "Menu.h"
//#include <windows.h>

int main() 
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Rusian");
    
    Menu menu;
    menu.run();
    
    cout << "Конец. (ура победа)" << endl;
    return 0;
}