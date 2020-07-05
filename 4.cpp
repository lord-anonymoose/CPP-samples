#include <iostream>
#define SIZE 255
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <istream>

//Вариант 25
//Ввести с клавиатуры строку  символов S1. Признак окончания ввода строки - нажатие клавиши "Ввод". Программа должна содержать перегруженную операцию «=», использование которой скопирует S1 в S2 .
//Длина L нечетная, то выделяется подстрока от последней цифры


class X{
    char *str;
    char *str_return;
public:
    X();
    X(char*);
    ~X();
    char* Run();
    char *get() {
    return str_return;
    }
    void Set(char*);
    X& operator = (X& s);
    friend void print(X&);
    friend std::ostream& operator<<(std::ostream&,X&);
    friend std::istream& operator>>(std::istream&,X&);
    friend char* Run(X&);
};
X::X(){
    str=new char[SIZE];
    str[0]='\0';
    str_return=new char[SIZE];
    str_return[0]='\0';
};

X::X(char *s){
    str=new char[SIZE];
    strcpy(str,s);
    str_return=new char[SIZE];
    str_return[0]='\0';
};

X::~X(){
    delete[] str;
    std::cout<<"...Был вызван деструктор"<<std::endl;
};

void X::Set(char* s)
{
    for (unsigned int i=0;i<strlen(s);i++){
        str[i]=s[i];
        str[i]='\0';
    };
}

X& X::operator = (X& s)
{
    strcpy(str, str_return);
    
    return *this;
}

char* X::Run()
    {
        int j=0;
        strcpy(str_return,str);
        if (strlen(str)%2==1) {
            for (int i=0;i<strlen(str);i++){
                if ( ((int)str[i]<=58) && ((int)str[i]>=47) ) {
                    for (j=0; j<=strlen(str); j++)
                         {str_return[j]=' '; }
                    j=0;
                }
                else {str_return[j]=str[i]; j++;}
                }
        }
        return str_return;
    };

char* Run(X &obj){return obj.Run();};

void print(X &obj){std:std::cout<<obj.str_return<<std::endl;};
std::ostream& operator<<(std::ostream &stream,X &ob) {
    stream << ob.str ;
    return stream;
};


std::istream &operator>>(std::istream &stream,X &ob){
    stream >> ob.str;
    return stream;
};

void addFile(X a) {
    FILE *f;
    f = fopen("res.txt.rtf", "w");
    fputs(a.get(), f);
    fclose(f);
    
}

int main (void){
    char s[265];
    while (true){
        std::cout<<"Enter - признак конца ввода. Введите строку:"<<std::endl;
    std::cin.getline(s,256);
    X str(s);
    std::cout<<"Результат работы программы:"<<std::endl;
    std::cout<<Run(str)<<std::endl;
        X *pstr = &str;
        pstr->Run();
        print(*pstr);
    }
};
