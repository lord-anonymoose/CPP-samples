//
//  main.cpp
//  #3
//
//  Created by Philipp on 26/11/2018.
//  Copyright © 2018 Philipp. All rights reserved.
//

#include <iostream>
#include <cmath>

class myFunction {
    float x,y,z,t;
public:
    myFunction (float X, float Y, float Z);
    myFunction(void)
    {
            std::cout<< "Введите значение переменной X"<<std::endl;
            while (true)
            {
                std::cin >>x;
                if(std::cin.fail()) {
                    std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                    std::cin.clear();
                    while(std::cin.get()!='\n');
                }
                else break;
            }
        
            std::cout<< "Введите значение переменной Y"<<std::endl;
            while (true)
            {
                std::cin >>y;
                if(std::cin.fail()) {
                    std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                    std::cin.clear();
                    while(std::cin.get()!='\n');
                }
                else break;
            }
        
            std::cout<< "Введите значение переменной Z"<<std::endl;
            while (true)
            {
                std::cin >>z;
                if(std::cin.fail()) {
                    std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                    std::cin.clear();
                    while(std::cin.get()!='\n');
                }
                else break;
            }
        }
    friend void print(const myFunction&);
    friend void run(myFunction&);
    ~myFunction (){};
};

void run(myFunction& object)
{
    if (object.z*object.z==15) {}
    else object.t=(2*cos(object.x-3.14/6))/(0.5+sin(object.y)*sin(object.y))*(1+object.z*object.z/(3-object.z*object.z/5));
};

void print(const myFunction& object)
{
    if (object.z*object.z==15) {std::cout<<"Одно из введеных чисел не входит в ОДЗ";}
    else std::cout<<"Результат работы программы: "<<object.t<<std::endl<<std::endl;
};

int main(int argc, const char * argv[])
{
    while (true){
        myFunction *Sample;
        Sample = new myFunction;
        run(*Sample);
        print(*Sample);
        delete Sample;
    }
}
