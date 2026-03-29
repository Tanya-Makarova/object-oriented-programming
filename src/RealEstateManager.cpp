#include "RealEstateManager.h"

RealEstateManager::RealEstateManager() {}

RealEstateManager::~RealEstateManager()
{
    for (auto obj : objects)
        delete obj;
}

void RealEstateManager::addObject(RealEstateObject* obj)
{
    objects.push_back(obj);
}

void RealEstateManager::removeObject(int index)
{
    if (index < 0 || index >= objects.size())
    {
        cout << "Неверный индекс!" << endl;
        return;
    }

    delete objects[index];
    objects.erase(objects.begin() + index);
}

RealEstateObject* RealEstateManager::getObject(int index)
{
    if (index < 0 || index >= objects.size())
        return nullptr;

    return objects[index];
}

int RealEstateManager::getSize() const
{
    return objects.size();
}

// Вывод информации

void RealEstateManager::showAllFull()
{
    if (objects.empty())
    {
        cout << "Список пуст" << endl;
        return;
    }

    for (int i = 0; i < objects.size(); i++)
    {
        cout << i + 1 << ". " << endl;
        objects[i]->printInfo();
        cout << "----------------------" << endl;
    }
}

void RealEstateManager::showAllPricePerSqm()
{
    for (int i = 0; i < objects.size(); i++)
    {
        cout << i + 1 << ". "
             << objects[i]->calcPricePerSqm() << " руб/м²" << endl;
    }
}

void RealEstateManager::showAllDescriptions()
{
    for (auto obj : objects)
    {
        cout << obj->getListingDescription() << endl;
    }
}

// Поиск

void RealEstateManager::searchByAddress(const string& address)
{
    bool found = false;

    for (auto obj : objects)
    {
        if (obj->getAddress() == address)
        {
            obj->printInfo();
            found = true;
        }
    }

    if (!found)
        cout << "Не найдено " << endl;
}

void RealEstateManager::filterByPriceRange(double minPrice, double maxPrice)
{
    for (auto obj : objects)
    {
        double price = obj->getPrice();

        if (price >= minPrice && price <= maxPrice)
            obj->printInfo();
    }
}

// Редактирование объекта

void RealEstateManager::editObject(int index)
{
    if (index < 0 || index >= objects.size())
    {
        cout << "Неверный индекс" << endl;
        return;
    }

    double newPrice;
    cout << "Введите новую цену: ";
    cin >> newPrice;

    objects[index]->setPrice(newPrice);
}

void RealEstateManager::updatePrice(int index, double newPrice)
{
    if (index >= 0 && index < objects.size())
        objects[index]->setPrice(newPrice);
}

// Денежные операции

void RealEstateManager::calculateProfitAll()
{
    for (auto obj : objects)
    {
        obj->calculateProfitWithCommission(0.1, 0.13);
        cout << "------------------" << endl;
    }
}

void RealEstateManager::calculateProfitOne(int index)
{
    if (index < 0 || index >= objects.size())
        return;
objects[index]->calculateProfitWithCommission(0.1, 0.13);
}

// Сбор и вывод статистики

void RealEstateManager::showStatistics()
{
    if (objects.empty())
    {
        cout << "Нет данных" << endl;
        return;
    }

    double totalPrice = 0;
    double totalSquare = 0;
    double max = 0;
    double min = 1e9;

    for (auto obj : objects)
    {
        double pricePerSqm = obj->calcPricePerSqm();

        totalPrice += obj->getPrice();
        totalSquare += obj->getSquare();

        if (pricePerSqm > max) max = pricePerSqm;
        if (pricePerSqm < min) min = pricePerSqm;
    }

    cout << "Всего объектов: " << objects.size() << endl;
    cout << "Средняя цена: " << totalPrice / objects.size() << endl;
    cout << "Средняя площадь: " << totalSquare / objects.size() << endl;
    cout << "Макс цена за м²: " << max << endl;
    cout << "Мин цена за м²: " << min << endl;
}
