#include<iostream>

#include"task_1.h"
#include "../global_utils.h"

void task1()
{
    setlocale(LC_ALL, "Russian"); //�������

    std::cout<<"----------------------------------------------------------------\n";
    std::cout<<"| ��������   �������   ����                                    |\n";
    std::cout<<"| ����� �.�. 2         ������� �� ��������������� � ��������   |\n";
    std::cout<<"----------------------------------------------------------------\n\n";

    char* number;
    while(true)
    {
        std::cout << "������� ����� � �������������� ����: ";
        number = get_bin_line();
        if (number[0] != '\0')break;
        else delete[] number;
    }

    const char* sign_info = "(�������������)";
    int sign = 1;
    if(number[0] == '1')
    {
        sign_info = "(�������������)";
        sign = -1;
    }
    std::cout<<"���������� �����: "<<number<<' '<<sign_info<<'\n';

    std::cout<<"����� � �������� ����: "<<from_add_to_reverse(number)<<'\n';

    delete[] number;
}