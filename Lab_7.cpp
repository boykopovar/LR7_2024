#include <iostream>

#include "global_utils.h"
#include "./Task_1/task_1.h"
#include "./Task_2/task_2.h"
#include "./Task_3/task_3.h"

int main()
{
    setlocale(LC_ALL, "Russian"); //удалить
    std::cout<<"--------------------------------------------------------\n";
    std::cout<<"| Выполнил   Вариант   LR                              |\n";
    std::cout<<"| Бойко А.О. 2         Лабораторная работа номер 7     |\n";
    std::cout<<"--------------------------------------------------------\n\n";

    while(true)
    {
        int choice=0;
        std::cout<<"\nМеню\n1 - Задание 1\n2 - Задание 2\n3 - Задание 3\n0 - Выход\n";
        std::cin>>choice;
        if(!check_istream()){break;}
        switch(choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;

            default: return 0;
        }
    }
    return 0;
}