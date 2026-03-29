#include "Menu.h"
#include "utils.h"
#include "Apartment.h"
#include "House.h"

void Menu::run() 
{
    int choice;
    do 
    { // Действия которые мы делаем независимо от условия в while
        clearScreen(); // Сначала отчистка экрана
        showMainMenu(); // Обзор меню
        choice = safeReadInt(); // Проверка, что число корректное
        if (choice != 0) 
        {
            submenu(choice); // Выполняем действие из мееню, если оно не "Назад"
        }
    } while (choice != 0);
}

void Menu::showMainMenu() 
{
    cout << "------- Главное меню -------" << endl;
    cout << "1. Просмотр объектов" << endl;
    cout << "2. Управление объектами (добавить новый)" << endl;
    cout << "3. Финансовые операции" << endl;
    cout << "4. Поиск и фильтрация" << endl;
    cout << "5. Статистика по объектам" << endl;
    cout << "0. Назад" << endl;
    cout << "-------------------------------" << endl;
    cout << "Выберите пункт: ";
}

void Menu::submenu(int choice) 
{
    switch(choice) 
    {
        case 1: viewMenu(); break;
        case 2: manageMenu(); break;
        case 3: financeMenu(); break;
        case 4: searchMenu(); break;
        case 5: statisticsMenu(); break;
        default: cout << "Неверный выбор!\n"; waitForEnter();
    }
}

void Menu::viewMenu() 
{
    int choice;
    do 
    {
        clearScreen();
        cout << "-------------Просмотр объектов ----------" << endl;
        cout << "1. Oписание" << endl;
        cout << "2. Цена за м² для всех объектов" << endl;
        cout << "3. Объявления" << endl;
        cout << "0. Назад" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Выберите пункт: ";
        
        choice = safeReadInt();
        
        switch(choice) 
        {
            case 1: manager.showAllFull(); break;
            case 2: manager.showAllPricePerSqm(); break;
            case 3: manager.showAllDescriptions(); break;
            case 0: break;
            default: cout << "Неверный выбор" << endl;
        }
        if (choice != 0) waitForEnter();
    } while (choice != 0);
}

void Menu::manageMenu() 
{
    int choice;
    do 
    {
        clearScreen();
        cout << "------------Управление объектами -----------" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Редактировать объект" << endl;
        cout << "3. Удалить объект" << endl;
        cout << "0. Назад" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Выберите пункт: ";
        
        choice = safeReadInt();
        
        switch(choice) 
        {
            case 1: 
            {
                int typeChoice;
                cout << "1. Квартира" << endl;
                cout << "2. Дом:" << endl;
                cout << "Выберите тип: ";
                typeChoice = safeReadInt();
                if (typeChoice == 1) addApartment();
                else if (typeChoice == 2) addHouse();
                break;
            }
            case 2: editObjectMenu(); break;
            case 3: 
            {
                manager.showAllFull();
                cout << "Введите номер объекта для удаления: ";
                int index = safeReadInt();
                if(index <= 0 || index > manager.getSize())
                {
                    cout << "Невреный номер" << endl;
                    return;
                }
                manager.removeObject(index - 1); // тк в массиве с 0 начинаются индексы
                break;
            }
            case 0: break;
            default: cout << "Неверный выбор" << endl;
        }
        if (choice != 0) waitForEnter();
    } while (choice != 0);
}

void Menu::financeMenu() 
{
    int choice;
    do 
    {
        clearScreen();
        cout << "-----------Финансовые операции --------------" << endl;
        cout << "1. Рассчитать прибыль для всех объектов" << endl;
        cout << "2. Рассчитать прибыль для конкретного объекта" << endl;
        cout << "0. Назад" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Выберите пункт: ";
        
        choice = safeReadInt();
        
        switch(choice) 
        {
            case 1: manager.calculateProfitAll(); break;
            case 2: 
            {
                manager.showAllFull();
                cout << "Введите номер объекта: ";
                int index = safeReadInt();
                manager.calculateProfitOne(index - 1);
                break;
            }
            case 0: break;
            default: std::cout << "Неверный выбор" << endl;
        }
        if (choice != 0) waitForEnter();
    } while (choice != 0);
}

void Menu::searchMenu() 
{
    int choice;
    do 
    {
        clearScreen();
        cout << "---------Поиск и фильтрация ---------------" << endl;
        cout << "1. Найти по адресу" << endl;
        cout << "2. Фильтр по цене (диапазон)" << endl;
        cout << "0. Назад" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Выберите пункт: ";
        
        choice = safeReadInt();
        
        switch(choice) {
            case 1: 
            {
                cout << "Введите адрес для поиска: ";
                string obj_address = safeReadLine();
                manager.searchByAddress(obj_address);
                break;
            }
            case 2: 
            {
                cout << "Минимальная цена: ";
                double minPrice = safeReadDouble();
                cout << "Максимальная цена: ";
                double maxPrice = safeReadDouble();
                manager.filterByPriceRange(minPrice, maxPrice);
                break;
            }
            case 0: break;
            default: cout << "Неверный выбор!" << endl;
        }
        if (choice != 0) waitForEnter();
    } while (choice != 0);
}

void Menu::statisticsMenu() {
    clearScreen();
    manager.showStatistics();
    waitForEnter();
}

void Menu::addApartment() {
    string address;
    double square, min_price, price;
    string type_of_serv;
    int rooms, floor;
    
    cout << "Добавление новой квартиры" << endl;
    cout << "Адрес: ";
    address = safeReadLine();

    cout << "Площадь (м²): ";
    square = safeReadDouble();

    cout << "Минимальная цена: ";
    min_price = safeReadDouble();

    cout << "Цена: ";
    price = safeReadDouble();

    cout << "Тип услуги (Продажа/Долгосрочная аренда/Аренда на сутки): ";
    type_of_serv = safeReadLine();

    cout << "Количество комнат: ";
    rooms = safeReadInt();

    cout << "Этаж: ";
    floor = safeReadInt();
    
    manager.addObject(new ApartmentListing(address, square, min_price, price, type_of_serv, rooms, floor));
    cout << "Квартира успешно добавлена" << endl;
}

void Menu::addHouse() {
    string address;
    double square, min_price, price, landArea, landPrice;
    string type_of_serv;
    bool hasGarage;
    
    cout << "Добавляем новый дом";
    cout << "Адрес: ";
    address = safeReadLine();

    cout << "Площадь дома (м²): ";
    square = safeReadDouble();

    cout << "Минимальная цена: ";
    min_price = safeReadDouble();

    cout << "Цена: ";
    price = safeReadDouble();

    cout << "Тип услуги (Продажа/Долгосрочная аренда/Аренда на сутки): ";
    type_of_serv = safeReadLine();

    cout << "Площадь участка (сотки): ";
    landArea = safeReadDouble();

    cout << "Цена за сотку: ";
    landPrice = safeReadDouble();

    cout << "Наличие гаража (y/n): ";
    string inp = safeReadLine();
    char garage = inp[0];
    hasGarage = (garage == 'y' || garage == 'Y'); // Избегая проверок разных вариантов написания
    
    manager.addObject(new HouseListing(address, square, min_price, price, type_of_serv, landArea, landPrice, hasGarage));
    cout << "Дом успешно добавлен!" << endl;
}

void Menu::editObjectMenu() 
{
    manager.showAllFull();
    cout << "Введите номер объекта: ";
    int index = safeReadInt();
    manager.editObject(index - 1);
}