#ifndef MENU_H
#define MENU_H

#include "RealEstateManager.h"

class Menu {
private:
    RealEstateManager manager;

    void showMainMenu();
    void submenu(int choice);

    void viewMenu();
    void manageMenu();
    void financeMenu();
    void searchMenu();
    void statisticsMenu();

    void addApartment();
    void addHouse();
    void editObjectMenu();

public:
    void run();
};

#endif