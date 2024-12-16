#include<iostream>

#include "../global_utils.h"
#include "task_4.h"


void task4()
{
    std::cout<<"-------------------------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   Суть                                             |\n";
    std::cout<<"| Бойко А.О. 2         Нахождение остатка от деления на простые числа   |\n";
    std::cout<<"-------------------------------------------------------------------------\n\n";

    int div=0;
    char* number;
    bool input_error = false;
    while(true)
    {
        if(input_error)std::cout<<"Ошибка! Введите натуральное число: \n";
        else std::cout<<"Введите число: ";
        number = get_number_line();
        if(number[0]=='\0')
        {
            input_error=true;
            delete[] number;
        }
        else break;
    }

    input_error=false;
    while(div<=0)
    {
        if(input_error)std::cout<<"Ошибка! Введитите простой делитель: ";
        else std::cout<<"Введитите простой делитель: ";
        std::cin>>div;
        if(!check_istream())div=0;
        input_error=true;
    }

    if(is_divisible(number, div)) std::cout<<"\nЧисло "<<number<<" *ДЕЛИТСЯ* на число "<<div<<" без остатка.";
    else std::cout<<"\nЧисло "<<number<<" *НЕ ДЕЛИТСЯ* на число "<<div<<" без остатка.\n";
    //std::cout<<"\nПравильный ответ "<<number<<" % "<<div<<" = "<<std::atoll(number)%static_cast<long long>(div)<<'\n';

    delete[] number;
}