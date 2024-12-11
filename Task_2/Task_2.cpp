#include<iostream>

#include"task_2.h"
#include "../global_utils.h"

void task2()
{
    setlocale(LC_ALL, "Russian"); //удалить

    std::cout<<"-----------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   Суть                               |\n";
    std::cout<<"| Бойко А.О. 2         Сложение в дополнительном коде     |\n";
    std::cout<<"-----------------------------------------------------------\n\n";

    char* number1;
    char* number2;
    char* sum;
    int sign1 = 1, sign2 = 1;

    std::cout << "Введите первое двочиное число в естественной форме (первый символ - знак):\n";
    number1 = input_bin_number(sign1);
    std::cout << "Введите второе двочиное число в естественной форме (первый символ - знак):\n";
    number2 = input_bin_number(sign2);

    sum = sum_of_binary(number1, sign1, number2, sign2);
    std::cout<<"\n"<<sum<<'\n';
    delete[] number1, number2, sum;
}