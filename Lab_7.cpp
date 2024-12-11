#include <iostream>

#include "global_utils.h"
#include "./Task_1/task_1.h"
#include "./Task_2/task_2.h"
#include "./Task_3/task_3.h"
#include "./Task_4/task_4.h"
#include "./Task_5/task_5.h"

int main()
{
    setlocale(LC_ALL, "Russian"); //�������
    std::cout<<"--------------------------------------------------------\n";
    std::cout<<"| ��������   �������   LR                              |\n";
    std::cout<<"| ����� �.�. 2         ������������ ������ ����� 7     |\n";
    std::cout<<"--------------------------------------------------------\n";

    while(true)
    {
        int choice=0;
        std::cout<<"\n���� LR7\n\n"
                           "1 - �� �������������� � ��������\n"
                           "2 - �������� � �������������� ����\n"
                           "3 - �������� � �������� ������� ���������\n"
                           "4 - ������� �� �����\n"
                           "5 - 239 ���������� �����\n"
                           "\n0 - �����\n";
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