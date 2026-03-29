#include "House.h"
// Конструктор: вызывает конструктор базового класса через список инициализации
HouseListing::HouseListing(string address, double square, double min_price, double price,
                 string type_of_service, double landArea, double landPricePerSotka, bool hasGarage)
        : RealEstateObject(address, square, min_price, price, type_of_service),
          landArea(landArea), landPricePerSotka(landPricePerSotka), hasGarage(hasGarage)
{
    // Дополнительная валидация
    if(this->landArea < 0) this->landArea = 0;
    if(this->landPricePerSotka < 0) this->landPricePerSotka = 0;
}
    
// Деструктор
HouseListing::~HouseListing()
{
    cout << "Деструктор HouseListing для дома: " << getAddress() << endl;
}
    
// Переопределение чисто виртуальных методов
double HouseListing::calcPricePerSqm()
{
    // Полная стоимость = цена дома + стоимость участка (площадь участка × цена за сотку)
    double totalPrice = price + (landArea * landPricePerSotka);
    // Цена за квадратный метр дома = полная стоимость / площадь дома
    return totalPrice / square;
}
    
string HouseListing::getListingDescription()
{
    string garageText = hasGarage ? "с гаражом" : "без гаража";
    string description = "Дом " + garageText + ", участок " + to_string((int)landArea) +
        " соток. Площадь дома: " + to_string((int)square) + " м². " +
        "Цена дома: " + to_string((int)price) + " руб. " +
        "Стоимость участка: " + to_string((int)(landArea * landPricePerSotka)) + " руб.";
    return description;
}
    
// Переопределение виртуального метода printInfo
void HouseListing::printInfo()
{
    RealEstateObject::printInfo();  // вызов базового метода
    cout << "Площадь участка: " << fixed << setprecision(1) << landArea << " соток" << endl;
    cout << "Стоимость одной сотки: " << fixed << setprecision(0) << landPricePerSotka << " руб." << endl;
    cout << "Общая стоимость участка: " << fixed << setprecision(0) << (landArea * landPricePerSotka) << " руб." << endl;
    cout << "Гараж: " << (hasGarage ? "есть" : "нет") << endl;
}
    
// Дополнительный геттер для специфичного поля
double HouseListing::getTotalPrice() const
{
    return price + (landArea * landPricePerSotka);
}