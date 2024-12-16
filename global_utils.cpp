#include <iostream>
#include "global_utils.h"

// O(n)
bool check_istream()
{
    char c = static_cast<char>(getchar());
    if(std::cin.fail() || (c!='\n' && c!= EOF))
    {
        std::cin.clear();
        while(c!='\n' && c!= EOF)
        {
            c = static_cast<char>(getchar());
        }
        return false;
    }
    else return true;
}

// O(n)
char* get_bin_line()
{
    long long int len =10;
    char* str = new char[len];
    for(long long int i=0;;++i)
    {
        char c = static_cast<char>(getchar());
        if(i>=len)
        {
            char* buf = new char[len];
            strcpy(buf, str);
            delete[] str;

            len*=10;
            str = new char[len];
            strcpy(str, buf);
            delete[] buf;
        }
        if(c=='\n' || c == EOF)
        {
            str[i]='\0';
            break;
        }
        else
        {
            if(c=='0' || c=='1') str[i]=c;
            else str[0]='\0';
        }
    }
    return str;
}

// O(n)
char* get_number_line()
{
    long long int len =10;
    char* str = new char[len];
    for(long long int i=0;;++i)
    {
        char c = static_cast<char>(getchar());
        if(i>=len)
        {
            char* buf = new char[len];
            strcpy(buf, str);
            delete[] str;

            len*=10;
            str = new char[len];
            strcpy(str, buf);
            delete[] buf;
        }
        if(c=='\n' || c == EOF)
        {
            str[i]='\0';
            break;
        }
        else
        {
            if(c>='0' && c<='9') str[i]=c;
            else str[0]='\0';
        }
    }
    return str;
}

// O(n)
void reverse_bits(char*& number)
{
    long long int len = strlen(number);
    for(long long int i=0;i<len;++i)
    {
        number[i] = (number[i] =='0') ? '1' : '0';
    }
}

// O(n)
void clean_zeroes(char*& number)
{
    //std::cout<<"\nIN:"<<number;
    long long int len = strlen(number);
    long long int first_index = len-2;
    for(long long int i=0;i<len;++i)
    {
        if(number[i]!='0' || i==len-1)
        {
            first_index=i;
            break;
        }
    }
    if(first_index==0)return;

    long long int new_len = len-first_index;
    char* clean_result = new char[new_len+1];
    clean_result[new_len]='\0';

    for(int j =0;j<new_len;++j)
    {
        clean_result[j]=number[first_index];
        ++first_index;
    }

    delete[] number;
    number = clean_result;
    //std::cout<<"\nOUT:"<<number<<'\n';
}

// O(n + m) нельзя однозначно выбрать n или m
void longer_number(char*& input_number, long long int target_len)
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
    input_number = result_number;
}

// O(n)
void char_to_start(char symbol, char*& str)
{
    long long int len = strlen(str);
    char* new_str = new char[len+2];
    new_str[0] = symbol;
    for(long long int i=0;i<len;++i)
    {
        new_str[i+1] = str[i];
    }
    delete[] str;
    new_str[len+1] ='\0';
    str = new_str;
}

// O(n) + O(2longer)
bool is_bigger(char* number1, char* number2)
{
    long long int max_len;
    bool result = false;

    long long int len_num1 = strlen(number1), len_num2 = strlen(number2);
    if(len_num1==len_num2)max_len = len_num1;
    else max_len = (len_num1 >= len_num2) ? len_num1 + 1 : len_num2 + 1;

    char* num1 = new char[max_len+1];
    char* num2 = new char[max_len+1];

    strcpy(num1, number1);
    strcpy(num2, number2);

    longer_number(num1, max_len);
    longer_number(num2, max_len);

    for(int i = 0;i<max_len;++i)
    {
        if(num1[i]>num2[i])
        {
            result = true;
            break;
        }
    }

    delete[] num1;
    delete[] num2;
    return result;
}

