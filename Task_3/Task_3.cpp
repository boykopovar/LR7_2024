#include<iostream>

#include"task_3.h"
#include "../global_utils.h"

void task3()
{
    setlocale(LC_ALL, "Russian"); //�������

    std::cout<<"----------------------------------------------------------------------------------\n";
    std::cout<<"| ��������   �������   ����                                                      |\n";
    std::cout<<"| ����� �.�. 2         �������� � ��������� ����� � ������ �������� ����������   |\n";
    std::cout<<"----------------------------------------------------------------------------------\n\n";

    int basic = 0;
    char sign1 = 1;
    char* number1;
    char* number2;
    char operation = '+';

    while(basic<=1)
    {
        std::cout << "������� ��������� ������� ����������: ";
        std::cin>>basic;
        if(!check_istream() || basic <= 1 || basic >55)
        {
            basic = 0;
            std::cout<<"������! ��������� ����� ���� �� ���� �� 55\n";
        }
    }
    while(true)
    {
        std::cout<<"������� ������ �����: ";

        sign1 = static_cast<char>(std::cin.get());
        if(sign1 != '+' && sign1!= '-')std::cin.unget();
        else if(sign1=='-')sign1=-1;

        number1 = get_custom_number(basic);
        if(number1[0]=='\0')
        {
            delete[] number1;
            sign1=1;
        }
        else break;
    }
    while(true)
    {
        std::cout<<"�������� �������� (+/-): ";
        operation = static_cast<char>(getchar());
        if(!check_istream())continue;
        if(operation == '+' || operation =='-')break;
    }
    while(true)
    {
        std::cout<<"������� ������ �����: ";
        number2 = get_custom_number(basic);
        if(number2[0]=='\0')delete[] number2;
        else break;
    }

    char* result = nullptr;
    if(operation == '-')
    {
        if(sign1==-1)
        {
            result = sum_custom_numbers(number2, number1, basic);
            std::cout<<'\n'<<'-'<<number1<<" - "<<number2<<" = -"<<result<<" ("<<basic<<")\n";
        }
        else if(is_bigger(number2, number1))
        {
            result = diff_custom_numbers(number2, number1, basic);
            std::cout<<'\n'<<number1<<" - "<<number2<<" = -"<<result<<" ("<<basic<<")\n";
        }
        else
        {
            result = diff_custom_numbers(number1, number2, basic);
            std::cout<<'\n'<<number1<<" - "<<number2<<" = "<<result<<" ("<<basic<<")\n";
        }
    }
    else // +
    {
        if(sign1==-1)
        {
            if(is_bigger(number1, number2))
            {
                result = diff_custom_numbers(number1, number2, basic);
                std::cout<<"\n-"<<number1<<" + "<<number2<<" = -"<<result<<" ("<<basic<<")\n";
            }
            else if(is_bigger(number2, number1))
            {
                result = diff_custom_numbers(number2, number1, basic);
                std::cout << "\n-" << number1 << " + " << number2 << " = " << result << " (" << basic << ")\n";
            }
            else
            {
                std::cout<<"\n-"<<number1<<" + "<<number2<<" = 0"<<" ("<<basic<<")\n";
            }
        }
        else
        {
            result = sum_custom_numbers(number1, number2, basic);
            std::cout << '\n' << number1 << " + " << number2 << " = " << result << " (" << basic << ")\n";
        }
    }

    delete[] result;
}