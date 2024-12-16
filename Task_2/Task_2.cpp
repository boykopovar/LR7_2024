#include<iostream>

#include"task_2.h"
#include "../global_utils.h"

void task2()
{
    std::cout<<"-----------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   Суть                               |\n";
    std::cout<<"| Бойко А.О. 2         Сложение в дополнительном коде     |\n";
    std::cout<<"-----------------------------------------------------------\n\n";

    char* number1;
    char* number2;
    char* sum;
    int sign1 = 1, sign2 = 1;
    char operation = '+';

    std::cout << "Введите первое двочиное число в естественной форме (первый символ - знак):\n";
    number1 = input_bin_number(sign1);
    std::cout << "Введите второе двочиное число в естественной форме (первый символ - знак):\n";
    number2 = input_bin_number(sign2);

    sum = sum_of_binary(number1, sign1, number2, sign2);
    if(sign1 == -1) char_to_start('-', number1);
    if(sign2 == -1) operation = '-';

    char sum_sign = '+';
    if(sum[0]=='1')sum_sign = '-';
    std::cout << "\n" << number1 << ' ' << operation << ' ' << number2 << " = " << sum;
    sum[0]=sum_sign;
    std::cout<<" ("<<sum<<")\n";

    delete[] number1;
    delete[] number2;
    delete[] sum;
}