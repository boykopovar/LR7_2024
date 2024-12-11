#pragma once
#include <iostream>

#include "task_2.h"
#include "../global_utils.h"


char* sum_of_binary(char* number_1, int sign_1, char* number_2, int sign_2)
{
    long long int len_num1 = strlen(number_1), len_num2 = strlen(number_2);
    long long int max_len = len_num1>=len_num2 ? len_num1 + 1 : len_num2 + 1;
    bool is_minus = false;

    add_zeroes_to_bin(number_1, max_len);
    add_zeroes_to_bin(number_2, max_len);

    if(sign_1 == -1)
    {
        reverse_bits(number_1);
        plus_one(number_1);
        is_minus = true;
    }
    if(sign_2 == -1)
    {
        reverse_bits(number_2);
        plus_one(number_2);
        is_minus = true;
    }

    char* answer =  bitwise_sum(number_1, number_2);
    if(is_minus && answer[0]!='0')
    {
        reverse_bits(answer);
        plus_one(answer);
    }
    return answer;
}

char* bitwise_sum(const char* num1, const char* num2)
{
    std::cout<<"Побитовое сложение:\n"<<num1<<'\n'<<num2<<'\n';
    unsigned int len = strlen(num1), len2 = strlen(num2);
    if(len!=len2)
    {
        char* sum = new char[1];
        sum[0]='\0';
        return sum;
    }

    char* sum = new char[len+1];
    sum[len]='\0';
    int buf = 0;

    for(long long int i = 0;i<len;++i)
    {
        int i_sum = (num1[len-1-i]-'0') + (num2[len-1-i]-'0') + buf;
        if(i_sum>1)
        {
            buf=1;
            i_sum -= 2;
        }
        else buf = 0;
        sum[len-1-i]=static_cast<char>(i_sum +'0');
    }
    return sum;
}

void add_zeroes_to_bin(char*& input_number, long long int target_len)
{
    long long int input_len = strlen(input_number);
    if(input_len>= target_len) return;

    char* result_number = new char[target_len+1];
    long long int len_delta = target_len-input_len;

    for(long long int i=0;i<len_delta;++i)
    {
        result_number[i]='0';
    }
    for(long long int i=len_delta;i<target_len;++i)
    {
        result_number[i] = input_number[i-len_delta];
    }
    result_number[target_len]='\0';

    delete[] input_number;
    input_number = result_number;
}

void plus_one(char*& number)
{
    long long int len = strlen(number);
    for(long long int i = len-1;i>=0;--i)
    {
        if(number[i]=='0')
        {
            number[i]='1';
            break;
        }
        else //number[i] == 1
        {
            number[i] = '0';
        }
    }
}

char* input_bin_number(int& back_sign_of_input)
{
    char* result_number;
    while(true)
    {
        char sign_char1 = static_cast<char>(getchar());
        if(sign_char1 == '-') back_sign_of_input = -1;
        else if(sign_char1 == '+') back_sign_of_input = 1;
        else if (sign_char1 == '1' || sign_char1 == '0') ungetc(sign_char1, stdin);
        else
        {
            check_istream();
            std::cout<<"Первым символом введите знак (+/-), например: -101\n";
            break;
        }
        result_number = get_bin_line();
        if (result_number[0] != '\0')break;
        else
        {
            delete[] result_number;
            back_sign_of_input = 1;
        }
    }
    return result_number;
}