#include <iostream>

#include "global_utils.h"
#include "./Task_1/task_1.h"
#include "./Task_2/task_2.h"
#include "./Task_3/task_3.h"
#include "./Task_4/task_4.h"
#include "./Task_5/task_5.h"

int main()
{
    setlocale(LC_ALL, "Russian"); //удалить
    std::cout<<"--------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   LR                              |\n";
    std::cout<<"| Бойко А.О. 2         Лабораторная работа номер 7     |\n";
    std::cout<<"--------------------------------------------------------\n";

    while(true)
    {
        int choice=0;
        std::cout<<"\nМеню LR7\n\n"
                           "1 - Из допонительного в обратный\n"
                           "2 - Сложение в дополнительном коде\n"
                           "3 - Сложение в заданной системе счисления\n"
                           "4 - Делится ли число\n"
                           "5 - 239 безвредных бочек\n"
                           "\n0 - Выход\n";
        std::cin>>choice;
        if(!check_istream()){break;}
        switch(choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;

            default: return 0;
        }
    }
    return 0;
}