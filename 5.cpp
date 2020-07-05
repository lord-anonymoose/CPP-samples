//
//  main.cpp
//  #5
//
//  Created by Philipp on 01/12/2018.
//  Copyright © 2018 Philipp. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <istream>
//Вариант 1 Сумму компонент классов
class X
{
public:
    int *x1;
    int *x2;
    X(int, int);
    ~X();
    virtual void print();
    virtual void Set();
};

class Y:public X{
public:
    int *y;
    Y(int, int, int);
    ~Y(){
        std::cout<<"Работает деструктор Y!"<<std::endl;
        delete y;
    }
    void Run(){
        std::cout<<"Сумма компонентов классов = "<<(*x1)+(*x2)+(*y)<<std::endl;
        std::cout<<"-----------------"<<std::endl;
    }
    void print(){
        std::cout<<"Работает виртуальная функция!"<<std::endl;
        std::cout<<"x1="<<*x1<<" x2="<<*x2<<" y="<<*y<<std::endl;
    }
    void Set(){
        std::cout<<"Введите x1: ";
        std::cin>>*x1;
        std::cout<<std::endl<<"Введите x2: ";
        std::cin>>*x2;
        std::cout<<std::endl<<"Введите y: ";
        std::cin>>*y;
    }
};


X::X(int X1, int X2){
    std::cout<<"Работает конструктор X!"<<std::endl;
    x1=new int(X1);
    x2=new int(X2);
}

void X::print(){
    std::cout<<"x1="<<*x1<<" x2="<<*x2<<std::endl;
};
void X::Set(){
    std::cout<<"Введите x1: ";
    std::cin>>*x1;
    std::cout<<"Введите x2: ";
    std::cin>>*x2;
    std::cout<<"-----------------"<<std::endl;
}

X::~X(){
    std::cout<<"Работает деструктор X!"<<std::endl;
    delete x1;
    delete x2;
};

Y::Y(int X1, int X2, int Y1):X(X1,X2){
    std::cout<<"Работает конструктор Y!"<<std::endl;
    y=new int(Y1);
    std::cout<<"-----------------"<<std::endl;
};

int main(void){
    int a,b,c;
    while (true)
    {
    std::cout<<"Введите x1: ";
    std::cin>>a;
    std::cout<<std::endl<<"Введите x2: ";
    std::cin>>b;
    std::cout<<std::endl<<"Введите y: ";
    std::cin>>c;
    Y m(a,b,c);
    m.print();
    m.Run();
    m.Set();
    m.print();
    m.Run();
    std::cin.ignore();
    std::cin.get();
    std::cout<<std::endl;
    std::cout<<std::endl;
    }
};
