#include "iostream"
template <typename T>
class Mas
{
private:
    T N;
    T* mas;
    T* masOut;
public:
    void set(T N);
    void print(T N);
    Mas(T N); //
    Mas();
    ~Mas();
};
template <typename T>
Mas<T>::Mas(T N)
{
    mas = new T [N];
    masOut = new T [N];
    for(int i = 0; i < N; i++)
    {
        std::cin>>mas[i];
    }
}
template <typename T>
Mas<T>::~Mas()
{
    delete [] mas;
}

template <typename T>
Mas<T>::Mas()
{}

template <typename T>
void Mas<T>::set(T N)
{
    mas = new T [N];
    for(int i = 0; i < N; i++)
    {
        std::cout<<"Введите элемент массива:"<<std::endl;
        std::cin>>mas[i];
        std::cout<<std::endl;

        
    }
    
};

template <typename T>
void Mas<T>::print(T N)
{
    masOut = new T [N];
    int j = 0;
    //std::cout<<"Работает функция print";
    for(int i = 0; i < N; i++)
    {   j = j + mas[i];
        masOut[i] = j;
        std::cout<<masOut[i]<<std::endl;
    }
    
}


int main(int argc, char* argv[])
{
    Mas<int> a;
    a.set(3);
    std::cout<<std::endl;
    a.print(3);
    return 0;
}

