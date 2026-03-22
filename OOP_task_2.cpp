#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
        vector<string> types = {"Продажа", "Долгосрочная аренда", "Аренда на сутки"}; // Вектор (динамический массив) допустимых типов услуг
        double commissionRate = 0.05; // комиссия агентства
        double taxRate = 0.13;        // 13% налог
    
    public:    // Публичная секция
        RealEstateObject(string m_address, double m_square, double m_min_price, 
                     double m_price, string m_type_of_service) //конструткор - создается всегда при объявлении класса
        {
            // Присваиваем полям значения
            address = m_address;
            // Проверяем площадь: если положительная - берем её, иначе ставим 0.0
            // Тернарный оператор: (условие) ? значение_если_истина : значение_если_ложь
            square = (m_square > 0) ? m_square : 0.0;
            // Проходим по всем доступным типам услуг (вектор types)
            for(int i = 0; i < types.size(); i++)
            {
                if(types[i] == m_type_of_service) // Если тип не найден, type_of_service останется пустой строкой
                {
                    type_of_service = m_type_of_service;
                    break;
                };
            };

            min_price = (m_min_price > 0) ? m_min_price : 0.0;
            price = (m_price >= min_price) ? m_price : min_price;
        }
        // Виртуальный деструктор (обязателен для полиморфного удаления)
        virtual ~RealEstateObject()
        {
            cout << "Деструктор RealEstateObject для объекта по адресу: " << address << endl;
        }

        // Чисто виртуальные методы (должны быть переопределены в производных классах)
        virtual double calcPricePerSqm() = 0;            // возвращает цену за м²
        virtual string getListingDescription() = 0;      // возвращает описание объявления

        // Виртуальный метод printInfo (может быть переопределен)
        virtual void printInfo()                       // выведем всю информацию об объекте
        {
            cout << "Адрес недвижимости: " << address << endl;
            cout << "Площадь: " << fixed << setprecision(1) << square << " м²" << endl;
            cout << "Тип услуги: " << type_of_service << endl;
            cout << "Минимальная стоимость: " << fixed << setprecision(0) << min_price << " руб." << endl;
            cout << "Стоимость: " << fixed << setprecision(0) << price << " руб." << endl;
        }

        // Обычный метод (общий для всех, не переопределяется)
        double calculateProfitWithCommission() 
        {            
            double commission = price * commissionRate; // Расчет комиссии агентства (процент от цены)
            double tax = (price - commission) * taxRate; // Расчет налога (налог платится с суммы после вычета комиссии)
            double netProfit = price - commission - tax; // Чистая прибыль = цена - комиссия - налог
            
            cout << "Расчет прибыли с учетом услуг нашего риелторского агенства" << endl;
            cout << "Цена продажи/сдачи: " << fixed << setprecision(0) << price << endl;
            cout << "Комиссия агентства (" << commissionRate * 100 << "%): " << fixed << setprecision(0) << commission << endl;
            cout << "Налог (" << taxRate * 100 << "%): " << fixed << setprecision(2) << tax << endl;
            cout << "Чистая прибыль клиента: " << fixed << setprecision(2) << netProfit << endl;
            
            return netProfit;
        }

        // getters - получение значения приватных полей
        string getAddress() const { return address; }
        double getSquare() const { return square; }
        double getMinPrice() const { return min_price; }
        string getTypeOfService() const { return type_of_service; }
        double getPrice() const { return price; }

        // setters - методы изменения приватных полей
        void setAddress(string new_address)
        {
            address = new_address;
            cout << "Вы изменили адрес. Новый адрес: "<< address << endl;
        }
        void setSquare(double new_square)
        {
            if(new_square >= 0)
            {
                square = new_square;
                cout << "Вы раздвинули стены? Хорошо, новая площадь: " << square << endl;
            }
            else cout << "Некорректное значение" << endl;
        }
        void setType(string m_type_of_service)
        {
            for(int i = 0; i < types.size(); i++)
            {
                if(types[i] == m_type_of_service)
                {
                    type_of_service = m_type_of_service;
                    cout << "Тип услуги успешно изменен на:  " << type_of_service << endl;
                    return;
                }
            };
            cout << "Нет указанного типа услуги" << endl;
        }
        void setMinPrice(double new_min_price)
        {
            if(new_min_price > 0)
            {
                min_price = new_min_price;
                cout << "Минимальная цена теперь: " << min_price << endl;
            }
            else cout << "Минимальная цена не может быть 0" << endl;
        }
        void setPrice(double new_price)
        {
            if(new_price >= min_price) // Проверка: новая цена не может быть меньше минимальной
            {
                price = new_price;
                cout << "Цена успешно установлена: " << price << endl;
            }
            else cout << "Ваша цена меньше минимальной" << endl;
        }

};
// Производный класс ApartmentListing (квартира)
class ApartmentListing : public RealEstateObject
{
    private:
        int floor;
        int rooms;
    public:
        // Конструктор: вызывает конструктор базового класса через список инициализации
        ApartmentListing(string address, double square, double min_price, double price, string type_of_service, int rm, int fl)
            : RealEstateObject(address, square, min_price, price, type_of_service), rooms(rm), floor(fl) 
        {
            // Дополнительная валидация (поля уже инициализированы в списке инициализации)
            if(this->rooms <= 0) this->rooms = 1;
            if(this->floor <= 0) this->floor = 1;
        }   
        // Деструктор
        ~ApartmentListing()
        {
            cout << "Деструктор ApartmentListing для квартиры: " << getAddress() << endl;
        }

        double calcPricePerSqm() override
        {
            // Цена за квадратный метр = общая цена / площадь
            return price / square;
        }
        string getListingDescription() override
        {
            string description = "Квартира: " + to_string(rooms) + "-комнатная, " +
                                to_string(floor) + " этаж. Площадь: " + to_string((int)square) +
                                " м². Цена: " + to_string((int)price) + " руб.";
            return description;
        }
        void printInfo() override
        {
            RealEstateObject :: printInfo(); // вызов базового метода
            cout << "Этаж: " << floor << endl;
            cout << "Количество комнат: " << rooms << endl;
        }
};
// Производный класс HouseListing (дом с участком)
class HouseListing : public RealEstateObject
{
    private:
        double landArea; // в сотках
        bool hasGarage;
        double landPricePerSotka; // стоимость одной сотки земли (руб)
    public:
    // Конструктор: вызывает конструктор базового класса через список инициализации
    HouseListing(string address, double square, double min_price, double price,
                 string type_of_service, double landArea, double landPricePerSotka, bool hasGarage)
        : RealEstateObject(address, square, min_price, price, type_of_service),
          landArea(landArea), landPricePerSotka(landPricePerSotka), hasGarage(hasGarage)
    {
        // Дополнительная валидация
        if(this->landArea < 0) this->landArea = 0;
        if(this->landPricePerSotka < 0) this->landPricePerSotka = 0;
    }
    
    // Деструктор
    ~HouseListing()
    {
        cout << "Деструктор HouseListing для дома: " << getAddress() << endl;
    }
    
    // Переопределение чисто виртуальных методов
    double calcPricePerSqm() override
    {
        // Полная стоимость = цена дома + стоимость участка (площадь участка × цена за сотку)
        double totalPrice = price + (landArea * landPricePerSotka);
        // Цена за квадратный метр дома = полная стоимость / площадь дома
        return totalPrice / square;
    }
    
    string getListingDescription() override
    {
        string garageText = hasGarage ? "с гаражом" : "без гаража";
        string description = "Дом " + garageText + ", участок " + to_string((int)landArea) +
                             " соток. Площадь дома: " + to_string((int)square) + " м². " +
                             "Цена дома: " + to_string((int)price) + " руб. " +
                             "Стоимость участка: " + to_string((int)(landArea * landPricePerSotka)) + " руб.";
        return description;
    }
    
    // Переопределение виртуального метода printInfo
    void printInfo() override
    {
        RealEstateObject::printInfo();  // вызов базового метода
        cout << "Площадь участка: " << fixed << setprecision(1) << landArea << " соток" << endl;
        cout << "Стоимость одной сотки: " << fixed << setprecision(0) << landPricePerSotka << " руб." << endl;
        cout << "Общая стоимость участка: " << fixed << setprecision(0) << (landArea * landPricePerSotka) << " руб." << endl;
        cout << "Гараж: " << (hasGarage ? "есть" : "нет") << endl;
    }
    
    // Дополнительный геттер для специфичного поля
    double getTotalPrice() const
    {
        return price + (landArea * landPricePerSotka);
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    const int SIZE = 4;
    RealEstateObject* objects[SIZE];
    // Заполнение массива объектами разных производных классов
    // Квартира 1: 2-комнатная на 5 этаже (продажа)
    objects[0] = new ApartmentListing("ул. Ленина, д. 5, кв. 25", 45.5, 5500000, 6800000,
                                      "Продажа", 2, 5);
    
    // Дом 1: с участком 6 соток, гараж есть (продажа)
    objects[1] = new HouseListing("ул. Пушкина, д. Колотушкина", 120.0, 50500000, 100000000,
                                  "Продажа", 6.0, 50000, true);
    
    // Квартира 2: 1-комнатная на 3 этаже (долгосрочная аренда)
    objects[2] = new ApartmentListing("пр. Мира, д. 2, кв. 12", 32.0, 55000, 55000,
                                      "Долгосрочная аренда", 1, 3);
    
    // Дом 2: с участком 4.2 сотки, гаража нет (аренда на сутки)
    objects[3] = new HouseListing("ул. Лесная, д. 7", 95.0, 5000, 5200,
                                  "Аренда на сутки", 4.2, 30000, false);
    
    cout << "\n---- Расчет цены за квадратный метр ----\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\nОбъект " << i+1 << endl;
        cout << "Цена за м²: " << fixed << setprecision(2) << objects[i]->calcPricePerSqm() << " руб." << endl;
    }
    
    cout << "\n ---- Описание ----\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\n--- Объект " << i+1 << " ---" << endl;
        cout << objects[i]->getListingDescription() << endl;
    }
    
    // Расчет прибыли
    cout << "\n----------- Расчет прибыли -----------\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\n Объект " << i+1 << " " << endl;
        objects[i]->calculateProfitWithCommission();
    }
    
    // Освобождение памяти (вызов деструкторов)
    cout << "\n----- Освобождение памяти -----\n";
    for(int i = 0; i < SIZE; i++)
    {
        delete objects[i];  // виртуальный деструктор обеспечит корректное удаление
    }
    
    cout << "Конец" << endl;
    
    return 0;
}