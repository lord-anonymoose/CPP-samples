#include <iostream>

int main(int argc, const char * argv[]) {
    while (true)
    {
        std::cout<<"Введите количество элементов в 1 строке и 1 столбце матрицы (При этом пусть количество строк = количество столбцов).";
        std::cout<<std::endl;
        int n;
        while (true)
        {
            std::cin >>n;
            if(std::cin.fail()) {
                std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                std::cin.clear();
                while(std::cin.get()!='\n');
            }
            else break;
        }
        int **array;
        array = new int*[n];
        for (int i = 0; i < n; i++)
            array[i] = new int[n];
        std::cout<<std::endl;
        std::cout<<"Настало время заполнить этот двумерный массив.";
        std::cout<<"Если хотите сделать это самостоятельно, введите 0. Иначе введите 1 и массивы заполнятся случайным образом.";
        std::cout<<std::endl;
        int inputType;
        while (true)
        {
            std::cin >>inputType;
            if(inputType>1) {
                std::cout<<"Вы ввели неправильное число! Попробуйте снова."<<std::endl;
                std::cin.clear();
                while(std::cin.get()!='\n');
            }
            if(std::cin.fail()) {
                std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                std::cin.clear();
                while(std::cin.get()!='\n');
            }
            else
            {if (inputType==0) {
                std::cout << "Вводите числа, после каждого нажимая клавишу Enter";
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Хорошо.";
                std::cout<<std::endl;
                for (int  i=0; i<n; i++)
                    for (int j=0; j<n; j++)
                    {
                        while (true){
                            std::cin >> *(*(array+i) + j);
                            if(std::cin.fail()) {
                                std::cout<<"Вы ввели не число! Попробуйте снова."<<std::endl;
                                std::cin.clear();
                                while(std::cin.get()!='\n');
                            } else break;
                        }
                    }
                break;
            }
                
                if (inputType==1) {
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<"Хорошо. Вот наш массив:";
                    std::cout<<std::endl;
                    for (int  i=0; i<n; i++)
                        for (int j=0; j<n; j++)
                        {
                            *(*(array+i) + j)=rand()%100-50;
                        }
                    break;
                    
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++){
                if (*(*(array + i) + j)>-1) std::cout<<" ";
                if (*(*(array + i) + j)>-1 and *(*(array+i) + j)<10) std::cout<<" ";
                if (*(*(array+ i ) + j)>-10 and *(*(array+i) + j)<0) std::cout<<" ";
                std::cout << *(*(array + i) + j);
                std::cout<<" ";
            }
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
        std::cout << ("Следующие элементы находятся под главной диагональю нашей матрицы:");
        std::cout << std::endl;
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if (j<i){
            std::cout << *(*(array+i) + j) << " ";
            std::cout << std::endl;
                }
        }
        for (int counter=0; counter<5; counter++) std::cout<<std::endl;
        for(int i=0;i<n;i++)
            delete[] array[i];
        delete[] array;
    }
}

