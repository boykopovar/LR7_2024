#include<iostream>

#include"task_2.h"
#include "../global_utils.h"

void task2()
{
    setlocale(LC_ALL, "Russian"); //�������

    std::cout<<"-----------------------------------------------------------\n";
    std::cout<<"| ��������   �������   ����                               |\n";
    std::cout<<"| ����� �.�. 2         �������� � �������������� ����     |\n";
    std::cout<<"-----------------------------------------------------------\n\n";

    char* number1;
    char* number2;
    char* sum;
    int sign1 = 1, sign2 = 1;

    std::cout << "������� ������ �������� ����� � ������������ ����� (������ ������ - ����):\n";
    number1 = input_bin_number(sign1);
    std::cout << "������� ������ �������� ����� � ������������ ����� (������ ������ - ����):\n";
    number2 = input_bin_number(sign2);

    sum = sum_of_binary(number1, sign1, number2, sign2);
    std::cout<<"\n"<<sum<<'\n';
    delete[] number1, number2, sum;
}