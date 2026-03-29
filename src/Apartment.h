#ifndef APARTMENT_H // Производный класс ApartmentListing (квартира)
#define APARTMENT_H

#include "OBJECTS_LIST.h"

class ApartmentListing : public RealEstateObject
{
    private:
        int floor;
        int rooms;
    public:
        // Конструктор: вызывает конструктор базового класса через список инициализации
        ApartmentListing(string address, double square, double min_price, double price, string type_of_service, int rm, int fl);
        ~ApartmentListing();
        double calcPricePerSqm() override;
        string getListingDescription() override;
        void printInfo() override;
};
#endif