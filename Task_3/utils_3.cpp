#include <iostream>

#include "task_3.h"
#include "../global_utils.h"


char* get_custom_number(int basic)
{
    long long int len =10;
    char* str = new char[len];
    for(long long int i=0;;++i)
    {

        char c = static_cast<char>(getchar());
        if (c<'0' || c>'z')
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
            if(c>='0' && c<'0'+7+basic && 'z'>=c)
            {
                if(c<='9' || c>='A') str[i]=c;
            }
            else str[0]='\0';
        }
    }
    return str;
}

char* sum_custom_numbers(char* number1, char* number2, int basic)
{
    long long int len_num1 = strlen(number1), len_num2 = strlen(number2);
    long long int max_len = (len_num1 >= len_num2) ? len_num1 + 1 : len_num2 + 1;
    char* result = new char[max_len];
    result[max_len]='\0';

    longer_number(number1, max_len);
    longer_number(number2, max_len);

    int buf = 0;
    for(long long int i = max_len-1;i>=0;--i)
    {
        int sum = (char_to_value(number1[i]) + char_to_value(number2[i]) +buf);
        buf = 0;
        if(sum>=basic)
        {
            buf =1;
            sum -=basic;
        }
        result[i]=static_cast<char>(value_to_char(sum));
    }
    clean_zeroes(result);
    return result;
}

char* diff_custom_numbers(char* number1, char* number2, int basic)
{
    long long int len_num1 = strlen(number1), len_num2 = strlen(number2);
    long long int max_len = (len_num1 >= len_num2) ? len_num1 + 1 : len_num2 + 1;
    char* result = new char[max_len];
    result[max_len]='\0';

    longer_number(number1, max_len);
    longer_number(number2, max_len);

    int buf = 0;
    for(long long int i = max_len-1;i>=0;--i)
    {
        int diff = (char_to_value(number1[i]) - char_to_value(number2[i]) -buf);
        buf = 0;
        if(diff<0)
        {
            buf =1;
            diff +=basic;
        }
        result[i]=static_cast<char>(value_to_char(diff));
    }
    clean_zeroes(result);
    return result;
}

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

    delete[] input_number;
    input_number = result_number;
}

int char_to_value(char c)
{
    if(c>='0' && c<= '9')return c-'0';
    else if(c>='A' && c<='Z')return c - 'A' + 10;
    else if(c>='a' && c <= 'z')return c - 'a' +36;
    else return -1;
}

char value_to_char(int value)
{
    if(value>=0 && value<= 9)return static_cast<char>(value+'0');
    else if(value>=10 && value<=35)return static_cast<char>(value + 'A' -10);
    else if(value>=36 && value <= 61)return static_cast<char>(value + 'a' -36);
    else return '\0';
}

bool is_bigger(char* number1, char* number2)
{
    long long int max_len;
    bool result = false;

    long long int len_num1 = strlen(number1), len_num2 = strlen(number2);
    if(len_num1==len_num2)max_len = len_num1;
    else max_len = (len_num1 >= len_num2) ? len_num1 + 1 : len_num2 + 1;

    char* num1 = new char[max_len];
    strcpy(num1, number1);
    char* num2 = new char[max_len];
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
    std::cout<<"yes\n";
    return result;
}
