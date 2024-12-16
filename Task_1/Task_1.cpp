#include<iostream>

#include"task_1.h"
#include "../global_utils.h"

void task1()
{
    std::cout<<"----------------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   Суть                                    |\n";
    std::cout<<"| Бойко А.О. 2         Перевод из дополнительного в обратный   |\n";
    std::cout<<"----------------------------------------------------------------\n\n";

    char* number;
    while(true)
    {
        std::cout << "Введите число в дополнительном коде: ";
        number = get_bin_line();
        if (number[0] != '\0')break;
        else delete[] number;
    }

    const char* sign_info = "(положительное)";
    int sign = 1;
    if(number[0] == '1')
    {
        sign_info = "(отрицательное)";
        sign = -1;
    }
    std::cout<<"Полученное число: "<<number<<' '<<sign_info<<'\n';

    std::cout<<"Число в обратном коде: "<<from_add_to_reverse(number)<<'\n';

    delete[] number;
}