#include<iostream>

#include "../global_utils.h"
#include "task_4.h"


void task4()
{
    setlocale(LC_ALL, "Russian"); //�������

    std::cout<<"-------------------------------------------------------------------------\n";
    std::cout<<"| ��������   �������   ����                                             |\n";
    std::cout<<"| ����� �.�. 2         ���������� ������� �� ������� �� ������� �����   |\n";
    std::cout<<"-------------------------------------------------------------------------\n\n";

    int div=0;
    char* number;
    bool input_error = false;
    while(true)
    {
        if(input_error)std::cout<<"������! ������� ����������� �����: \n";
        else std::cout<<"������� �����: ";
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
        if(input_error)std::cout<<"������! ��������� ������� ��������: ";
        else std::cout<<"��������� ������� ��������: ";
        std::cin>>div;
        if(!check_istream())div=0;
        input_error=true;
    }

    if(is_divisible(number, div)) std::cout<<"\n����� "<<number<<" *�������* �� ����� "<<div<<" ��� �������.";
    else std::cout<<"\n����� "<<number<<" *�� �������* �� ����� "<<div<<" ��� �������.\n";
    //std::cout<<"\n���������� ����� "<<number<<" % "<<div<<" = "<<std::atoll(number)%static_cast<long long>(div)<<'\n';

    delete[] number;
}