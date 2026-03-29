#include "OBJECTS_LIST.h"
RealEstateObject::RealEstateObject(string m_address, double m_square, double m_min_price, 
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

RealEstateObject:: ~RealEstateObject()
{
    cout << "Деструктор RealEstateObject для объекта по адресу: " << address << endl;
}

// setters - методы изменения приватных полей
void RealEstateObject::setAddress(string new_address)
{
    address = new_address;
    cout << "Вы изменили адрес. Новый адрес: "<< address << endl;
}
void RealEstateObject::setSquare(double new_square)
{
    if(new_square >= 0)
    {
        square = new_square;
        cout << "Вы раздвинули стены? Хорошо, новая площадь: " << square << endl;
    }
    else cout << "Некорректное значение" << endl;
    }
void RealEstateObject::setType(string m_type_of_service)
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
void RealEstateObject::setMinPrice(double new_min_price)
{
    if(new_min_price > 0)
    {
        min_price = new_min_price;
        cout << "Минимальная цена теперь: " << min_price << endl;
    }
    else cout << "Минимальная цена не может быть 0" << endl;
    }
void RealEstateObject::setPrice(double new_price)
{
    if(new_price >= min_price) // Проверка: новая цена не может быть меньше минимальной
    {
        price = new_price;
        cout << "Цена успешно установлена: " << price << endl;
    }
    else cout << "Ваша цена меньше минимальной" << endl;
}
// getters - получение значения приватных полей
string RealEstateObject::getAddress() const { return address; }
double RealEstateObject::getSquare() const { return square; }
double RealEstateObject::getMinPrice() const { return min_price; }
string RealEstateObject::getTypeOfService() const { return type_of_service; }
double RealEstateObject::getPrice() const { return price; }
double RealEstateObject::calculateProfitWithCommission(double commissionRate, double taxRate) 
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
void RealEstateObject::printInfo()                       // выведем всю информацию об объекте
        {
            cout << "Адрес недвижимости: " << address << endl;
            cout << "Площадь: " << fixed << setprecision(1) << square << " м²" << endl;
            cout << "Тип услуги: " << type_of_service << endl;
            cout << "Минимальная стоимость: " << fixed << setprecision(0) << min_price << " руб." << endl;
            cout << "Стоимость: " << fixed << setprecision(0) << price << " руб." << endl;
        }