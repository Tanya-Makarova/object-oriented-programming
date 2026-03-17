#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Класс, представляющий объект недвижимости (квартира, дом и т.д.)
class RealEstateObject 
{
    public:    // Публичная секция
        RealEstateObject(string m_address, double m_square, double m_price, string m_type_of_service) //конструткор - создается всегда при объявлении класса
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

            min_price = (m_price > 0) ? m_price : 0.0;
            price = min_price; // Начальная цена равна минимальной
        }
        
        void printInfo() // Выведем всю информацию об объекте
        {
            cout << "Адрес недвижимости: " << address << endl;
            cout << "Площадь: " << square << endl;
            cout << "Тип услуги: " << type_of_service << endl;
            cout << "Минимальная стоимость: " << min_price << endl;
            cout << "Стоимость: " << price << endl;
        }

        // Расчет прибыли с учетом комиссии агентства
        double calculateProfitWithCommission() 
        {            
            double commission = price * commissionRate; // Расчет комиссии агентства (процент от цены)
            double tax = (price - commission) * taxRate; // Расчет налога (налог платится с суммы после вычета комиссии)
            double netProfit = price - commission - tax; // Чистая прибыль = цена - комиссия - налог
            
            cout << "Расчет прибыли с учетом услуг нашего риелторского агенства" << endl;
            cout << "Цена продажи/сдачи: " << price << endl;
            cout << "Комиссия агентства (" << commissionRate * 100 << "%): " << commission << endl;
            cout << "Налог (" << taxRate * 100 << "%): " << tax << endl;
            cout << "Чистая прибыль клиента: " << netProfit << endl;
            
            return netProfit;
        }
        // getters - получение значения приватных полей
        string getAddress() const // const означает, что метод не изменяет объект
        {
            return address;
        }
        double getSquare() const
        {
            return square;
        }
        double getMinPrice() const
        {
            return min_price;
        }
        string getTypeRental() const
        {
            return type_of_service;
        }
        double getPrice() const
        {
            return price;
        }

        // setters - методы изменения приватных полей
        void setAddress(int new_address)
        {
            address = new_address;
        }
        void setSquare(double new_square)
        {
            if(new_square >= 0) square = new_square;
            else cout << "Некорректное значение" << endl;
        }
        void setType(string m_type_of_service)
        {
            for(int i = 0; i < types.size(); i++)
            {
                if(types[i] == m_type_of_service)
                {
                    type_of_service = m_type_of_service;
                    break;
                }
            };
            cout << "Нет типа указанной услуги" << endl;
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

    private: // Приватная секция
        string address;
        double square;
        double min_price;
        double price;
        string type_of_service;
        vector<string> types = {"Долгосрочная аренда", "Продажа", "Аренда на сутки"}; // Вектор (динамический массив) допустимых типов услуг
        double commissionRate = 0.05; // комиссия агентства
        double taxRate = 0.13;        // 13% налог
};

int main()
{
    setlocale(LC_ALL, "Rus");
    RealEstateObject realty_1("ул. Пушкина, дом Колотушкина", 2, 10000, "Долгосрочная аренда");  // Создаем объект недвижимости 
    realty_1.printInfo();
    realty_1.setPrice(70000); // Пытаемся изменить цену на 70000
    realty_1.calculateProfitWithCommission(); // Рассчитываем и выводим прибыль с учетом комиссии
    return 0;
}