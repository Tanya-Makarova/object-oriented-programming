#include "Apartment.h"
// Конструктор: вызывает конструктор базового класса через список инициализации
ApartmentListing::ApartmentListing(string address, double square, double min_price, double price, string type_of_service, int rm, int fl)
            : RealEstateObject(address, square, min_price, price, type_of_service), rooms(rm), floor(fl) 
{
    // Дополнительная валидация (поля уже инициализированы в списке инициализации)
    if(this->rooms <= 0) this->rooms = 1;
    if(this->floor <= 0) this->floor = 1;
};
// Деструктор
ApartmentListing::~ApartmentListing()
{
    cout << "Деструктор ApartmentListing для квартиры: " << getAddress() << endl;
}

double ApartmentListing::calcPricePerSqm()
{
    // Цена за квадратный метр = общая цена / площадь
    return price / square;
}
string ApartmentListing::getListingDescription()
{
    string description = "Квартира: " + to_string(rooms) + "-комнатная, " +
            to_string(floor) + " этаж. Площадь: " + to_string((int)square) +
                " м². Цена: " + to_string((int)price) + " руб.";
    return description;
}
void ApartmentListing::printInfo()
{
    RealEstateObject :: printInfo(); // вызов базового метода
    cout << "Этаж: " << floor << endl;
    cout << "Количество комнат: " << rooms << endl;
}