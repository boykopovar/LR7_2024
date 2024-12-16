#include <iostream>

#include "task_2.h"
#include "../global_utils.h"

// O(max_len)
char* sum_of_binary(char* number_1, int sign_1, char* number_2, int sign_2)
{
    long long int len_num1 = strlen(number_1), len_num2 = strlen(number_2);
    long long int max_len = len_num1>=len_num2 ? len_num1 + 2 : len_num2 + 2;
    bool is_minus = false;

    longer_number(number_1, max_len);
    longer_number(number_2, max_len);

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
    clean_zeroes(answer);
    char bin_sign_to_add = '0';
    if(sign_1 == -1 && sign_2 == -1) ;
    else if( (sign_1 == -1 && is_bigger(number_1, number_2) ) ||
             (sign_2 == -1 && is_bigger(number_2, number_1) ) ) bin_sign_to_add = '1';
    char_to_start(bin_sign_to_add, answer);

    return answer;
}

// O(len)
char* bitwise_sum(const char* num1, const char* num2)
{
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

//O(len)
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

// O(len)
char* input_bin_number(int& back_sign_of_input)
{
    char* result_number;
    bool error = false;
    while(true)
    {
        if(error)std::cout<<"Неправильный ввод, повторите попытку: ";
        char sign_char1 = static_cast<char>(getchar());
        if(sign_char1 == '-' || sign_char1 == '+')
        {
            char after_sign = static_cast<char>(getchar());

            if(after_sign=='\n')
            {
                std::cout<<"После знака (+/-) необходимо вводить число, например: -101: ";
                error=false;
            }
            if(after_sign!= '1' && after_sign != '0')
            {
                check_istream();
                error = true;
                continue;
            }
            ungetc(after_sign, stdin);
        }
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