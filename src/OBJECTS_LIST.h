#ifndef OBJECTS_LIST
#define OBJECTS_LIST

#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

//Класс, представляющий объект недвижимости (квартира, дом и т.д.)
class RealEstateObject 
{
    protected:
        string address;
        double square;
        double min_price;
        double price;
        string type_of_service;
        vector<string> types = {"Продажа", "Долгосрочная аренда", "Аренда на сутки"};
        double commissionRate; 
        double taxRate;
    
    public:    // Публичная секция
        RealEstateObject(string m_address, double m_square, double m_min_price, 
                     double m_price, string m_type_of_service); 
        virtual ~RealEstateObject();
        // Прописываем сеттеры
        void setAddress(string new_address);
        void setSquare(double new_square);
        void setType(string m_type_of_service);
        void setMinPrice(double new_min_price);
        void setPrice(double new_price);
        // Прописываем геттеры с константами, чтобы не использовать лишнюю память
        string getAddress() const;
        double getSquare() const;
        double getMinPrice() const;
        string getTypeOfService() const;
        double getPrice() const;
        double calculateProfitWithCommission(double commissionRate, double taxRate);
        virtual double calcPricePerSqm() = 0;
        virtual string getListingDescription() = 0;
        virtual void printInfo();
};
#endif