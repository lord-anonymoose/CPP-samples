//
//  main.cpp
//  #1
//
//  Created by Philipp on 07/11/2018.
//  Copyright © 2018 Philipp. All rights reserved.

// Вариант 10
//Заданы два массива А(5) и В(5). Подсчитать в них количество положительных элементов и первым на печать вывести массив, имеющий наибольшее их количество.

#include <iostream>

int main()
{
    while (true) {
        std::cout << "Итак, заданы два массива А и В. Нужно подсчитать в них количество положительных элементов и первым на печать вывести массив, имеющий наибольшее их количество.";
        std::cout << std::endl;
        std::cout << "Для начала введите коичество элементов в каждом из массивов (пусть оно будет одинаковым):";
        std::cout << std::endl;
        int n;
        while (true) {
            std::cin >> n;
            if (std::cin.fail()) {
                std::cout << "Вы ввели не число! Попробуйте снова." << std::endl;
                std::cin.clear();
                while (std::cin.get() != '\n')
                    ;
            }
            else {
                srand(time(NULL));
                std::cout << "Настало время заполнить наши массивы. Начнем с первого.";
                std::cout << std::endl;
                int* array1 = new int[n];
                std::cout << "Если хотите сделать это самостоятельно, введите 0. Иначе введите 1 и массивы заполнятся случайным образом.";
                std::cout << std::endl;
                int inputType;
                while (true) {
                    std::cin >> inputType;
                    if (std::cin.fail()) {
                        std::cout << "Вы ввели не число! Попробуйте снова." << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n')
                            ;
                    }
                    else {
                        if (inputType > 1) {
                            std::cout << "Вы ввели неправильное число! Попробуйте снова." << std::endl;
                            std::cin.clear();
                            while (std::cin.get() != '\n')
                                ;
                        }
                        
                        if (inputType == 0) {
                            std::cout << "Вводите числа, после каждого нажимая клавишу Enter";
                            std::cout << std::endl;
                            for (int i = 0; i < n; i++) {
                                while (true) {
                                    std::cin >> *(array1 + i);
                                    if (std::cin.fail()) {
                                        std::cout << "Вы ввели не число! Попробуйте снова." << std::endl;
                                        std::cin.clear();
                                        while (std::cin.get() != '\n')
                                            ;
                                    }
                                    else {
                                        break;
                                    };
                                }
                            }
                            break;
                        }
                    }
                    
                    if (inputType == 1) {
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "Хорошо. Вот элементы нашего массива:";
                        std::cout << std::endl;
                        for (int i = 0; i < n; i++) {
                            *(array1 + i) = rand() % 100 - 50;
                            std::cout << *(array1 + i);
                            std::cout << std::endl;
                        }
                        break;
                    }
                }
                
                std::cout << std::endl;
                std::cout << "Теперь заполним наш второй массив.";
                std::cout << std::endl;
                int* array2 = new int[n];
                std::cout << "Если хотите сделать это самостоятельно, введите 0. Иначе введите 1 и массивы заполнятся случайным образом.";
                std::cout << std::endl;
                while (true) {
                    std::cin >> inputType;
                    if (std::cin.fail()) {
                        std::cout << "Вы ввели не число! Попробуйте снова." << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n')
                            ;
                    }
                    else {
                        if (inputType > 1) {
                            std::cout << "Вы ввели неправильное число! Попробуйте снова." << std::endl;
                            std::cin.clear();
                            while (std::cin.get() != '\n')
                                ;
                        }
                        
                        if (inputType == 0) {
                            std::cout << "Вводите числа, после каждого нажимая клавишу Enter";
                            std::cout << std::endl;
                            for (int i = 0; i < n; i++) {
                                while (true) {
                                    std::cin >> *(array2 + i);
                                    if (std::cin.fail()) {
                                        std::cout << "Вы ввели не число! Попробуйте снова." << std::endl;
                                        std::cin.clear();
                                        while (std::cin.get() != '\n')
                                            ;
                                    }
                                    else {
                                        break;
                                    };
                                }
                            }
                            break;
                        }
                    }
                    
                    if (inputType == 1) {
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "Хорошо. Вот элементы нашего массива:";
                        std::cout << std::endl;
                        for (int i = 0; i < n; i++) {
                            *(array2 + i) = rand() % 100 - 50;
                            std::cout << *(array2 + i);
                            std::cout << std::endl;
                        }
                        break;
                    }
                }
                std::cout << std::endl;
                std::cout << "Супер!";
                std::cout << std::endl;
                
                int Number1 = 0;
                for (int i = 0; i < n; i++) {
                    if (*(array1 + i) >= 0) {
                        Number1++;
                    }
                }
                
                std::cout << "Хм...";
                std::cout << std::endl;
                
                int Number2 = 0;
                for (int i = 0; i < n; i++) {
                    if (*(array2 + i) >= 0) {
                        Number2++;
                    }
                }

                
                if (Number1 > Number2) {
                    std::cout << std::endl;
                    std::cout << "Выводим сначала первый массив, так как в нем большее положительных элементов (";
                    std::cout << Number1;
                    std::cout << ")";
                    std::cout << std::endl;
                    for (int i = 0; i < n; i++) {
                        std::cout << *(array1 + i);
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                    std::cout << "Теперь второй массив: (";
                    std::cout << Number2;
                    std::cout << ")";
                    
                    std::cout << std::endl;
                    for (int i = 0; i < n; i++) {
                        std::cout << *(array2 + i);
                        std::cout << std::endl;
                    }
                }
                if (Number2 > Number1) {
                    std::cout << std::endl;
                    std::cout << "Выводим сначала второй массив, так как в нем большее положительных элементов (";
                    std::cout << Number2;
                    std::cout << ")";
                    std::cout << std::endl;
                    for (int i = 0; i < n; i++) {
                        std::cout << *(array2 + i);
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                    std::cout << "Теперь первый массив: (";
                    std::cout << Number1;
                    std::cout << ")";
                    std::cout << std::endl;
                    for (int i = 0; i < n; i++) {
                        std::cout << *(array1 + i);
                        std::cout << std::endl;
                    }
                }
                
                if (Number2 == Number1) {
                    std::cout << "Видимо, в массивах одинаковое количество положительных элементов (";
                    std::cout << Number1;
                    std::cout << "). Может быть стоит попробовать ещё раз?";
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "_____________________________________________________________________________________________________________";
                std::cout << std::endl;
                std::cout << std::endl;
                delete[] array1;
                delete[] array2;
            }
        }
    }
}

