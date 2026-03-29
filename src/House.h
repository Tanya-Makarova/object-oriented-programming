#ifndef HOUSE_H
#define HOUSE_H

#include "OBJECTS_LIST.h"

// Производный класс HouseListing (дом с участком)
class HouseListing : public RealEstateObject
{
    private:
        double landArea; // в сотках
        bool hasGarage;
        double landPricePerSotka; // стоимость одной сотки земли (руб)
    public:
    HouseListing(string address, double square, double min_price, double price,
                 string type_of_service, double landArea, double landPricePerSotka, bool hasGarage);
    ~HouseListing();
    double calcPricePerSqm() override;
    string getListingDescription() override;
    void printInfo() override;
    // Дополнительный геттер для специфичного поля
    double getTotalPrice() const;
};
#endif