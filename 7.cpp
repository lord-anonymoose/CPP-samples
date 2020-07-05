#include <cstdlib>
#include <iostream>
#include <fstream>

class X
{
public:
    char *name;
    int *amount, h, *price, *type, *number, *speed;
    X()
    {
        name = new char[20];//наименование
        speed = new (int);//скорость передачи
        price = new (int);//цена
        type = new (int);//тип
        number = new (int);//кол во
        amount = new (int); //общая стоимость
    };
    virtual void print() = 0;
    virtual void get() = 0;
    void run()
    {
        std::cout << "Общая стоимость:" << std::endl;
        *amount = ((*(price))*(*(number)));
        h = *amount;
        std::cout << *amount;
    };
    ~X()
    {
        delete[] name;
        delete[] price;
        delete[] speed;
        delete[] number;
        delete[] type;
        delete[] amount;
    }
};


class nameClass : public X //Класс для создания, считывания и удаления имени
{
public:
    nameClass()
    {
        get();
    }
    void get()
    {
        std::cout << "Введите наименование:";
        std::cin.getline(name, 20);
    }
    void print()
    {
        std::cout << "наименование:" << name << std::endl;
    }
    
    ~nameClass()
    {
        delete[] name;
    }
};

class speedClass : public nameClass
{
public:
    speedClass()
    {
        get();
    }
    
    void get()
    {
        std::cout << "Введите скорость передачи данных:";
        std::cin >> *(X::speed);
    }
    
    void print()
    {
        std::cout << "Cкорость передачи данных: " << speed << std::endl;
    }
    ~speedClass()
    {
        delete[] speed;
    }
};

class typeClass : public virtual speedClass
{
public:
    typeClass()
    {
        get();
    }
    void get()
    {
        std::cout << "Введите тип:";
        std::cin >> *(X::type);
    }
    void print()
    {
        std::cout << "Тип:" << type << std::endl;
    }
    ~typeClass()
    {
        delete[] type;
    }
};

class numberClass : public virtual speedClass
{
public:
    numberClass()
    {
        get();
    }
    void get()
    {
        std::cout << "Кол-во: ";
        std::cin >> *(X::number);
    }
    void print()
    {
        std::cout << "Кол-во: " << number << std::endl;
    }
    ~numberClass()
    {
        delete[] number;
    }
};
class priceClass : public numberClass, public typeClass
{
public:
    priceClass()
    {
        get();
    }
    void get()
    {
        std::cout << "Введите Стоимость: ";
        std::cin >> *(X::price);
    }
    void print()
    {
        std::cout << "Стоимость: " << price << std::endl;
    }
    
    ~priceClass()
    {
        delete[] price;
    }
};

int main()
{
    setlocale(0, "");
    priceClass *w = new priceClass;
    w->run();
    {
        std::ofstream out("spisok.txt");
        out << "Наименование:" << w->name << '\n';
        out << "Скорость передачи данных:" << w->speed << '\n';
        out << "Кол-во:" << w->number << '\n';
        out << "Тип:" << w->type << '\n';
        out << "Стоимость:" << w->price << '\n';
        out << "Общая стоимость:" << w->h << '\n';
        out.close();
        std::cout << std::endl;
    }
}
