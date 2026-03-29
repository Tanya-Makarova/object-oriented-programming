#ifndef REAL_ESTATE_MANAGER_H
#define REAL_ESTATE_MANAGER_H

#include "OBJECTS_LIST.h"

class RealEstateManager {
private:
    std::vector<RealEstateObject*> objects;

public:
    RealEstateManager();
    ~RealEstateManager();

    void addObject(RealEstateObject* obj);
    void removeObject(int index);
    RealEstateObject* getObject(int index);
    int getSize() const;

    // Основные функции
    void showAllFull();
    void showAllPricePerSqm();
    void showAllDescriptions();

    void searchByAddress(const std::string& address);
    void filterByPriceRange(double minPrice, double maxPrice);

    void editObject(int index);
    void updatePrice(int index, double newPrice);

    // Финансы
    void calculateProfitAll();
    void calculateProfitOne(int index);

    // Статистика
    void showStatistics();
};

#endif