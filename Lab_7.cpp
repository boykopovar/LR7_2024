#include <iostream>

#include "global_utils.h"
#include "./Task_1/task_1.h"
#include "./Task_2/task_2.h"
#include "./Task_3/task_3.h"

int main()
{
    setlocale(LC_ALL, "Russian"); //�������
    std::cout<<"--------------------------------------------------------\n";
    std::cout<<"| ��������   �������   LR                              |\n";
    std::cout<<"| ����� �.�. 2         ������������ ������ ����� 7     |\n";
    std::cout<<"--------------------------------------------------------\n\n";

    while(true)
    {
        int choice=0;
        std::cout<<"\n����\n1 - ������� 1\n2 - ������� 2\n3 - ������� 3\n0 - �����\n";
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