//
//  main.cpp
//  #2
//
//  Created by Philipp on 21/11/2018.
//  Copyright © 2018 Philipp. All rights reserved.
//  Вариант 1
// ОДЗ:
//3 - z^2/5
//3 = z^2/5 - посторонний корень
//15 = z^2 => z=+-sqrt(15) - z не равно этому значению 

#include <iostream>
#include <cmath>

class myFunction {
    float x,y,z,t;
public:
    
    void set (float X, float Y, float Z)
    {
        x=X;
        y=Y;
        z=Z;
    }
    
    void run (void)
    {
        if (z*z==15) {}
        else
        {
            t=(2*cos(x-3.14/6))/(0.5+sin(y)*sin(y))*(1+z*z/(3-z*z/5));
            
        }
    }
    
    void print(void)
    {
        if (z*z==15)
        {
            std::cout<<"Одно из введенных в чисел не входит в область допустимых значений";
        }
        else
        std::cout<<"Результат работы нашей программы: "<<t;
        std::cout << std::endl;
    }
    
};

int main(int argc, const char * argv[]) {
    while (true){
    std::cout<< "Введите значение переменной X"<<std::endl;
    float x1;
    while (true)
    {
        std::cin >>x1;
        if(std::cin.fail()) {
            std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
            std::cin.clear();
            while(std::cin.get()!='\n');
        }
        else break;
    }
    std::cout<<std::endl;
    
    std::cout<< "Введите значение переменной Y"<<std::endl;
    float y1;
    while (true)
    {
        std::cin >>y1;
        if(std::cin.fail()) {
            std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
            std::cin.clear();
            while(std::cin.get()!='\n');
        }
        else break;
    }
    std::cout<<std::endl;
    
    std::cout<< "Введите значение переменной Z"<<std::endl;
    float z1;
    while (true)
    {
        std::cin >>z1;
        if(std::cin.fail()) {
            std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
            std::cin.clear();
            while(std::cin.get()!='\n');
        }
        else break;
    }
    std::cout<<std::endl;
    
    myFunction Fun1;
    Fun1.set(x1,y1,z1);
    Fun1.run();
    Fun1.print();
    std::cout << std::endl;
    
    myFunction *p1 = &Fun1;
    p1->set(x1,y1,z1);
    p1->run();
    p1->print();
    std::cout << std::endl;
    
    myFunction *p2 = new myFunction;
    p2->set(x1,y1,z1);
    p2->run();
    p2->print();
    delete p2;
    std::cout << std::endl;
    }
}
