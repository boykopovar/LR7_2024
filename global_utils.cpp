#include <iostream>
#include "global_utils.h"

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

void reverse_bits(char*& number)
{
    long long int len = strlen(number);
    for(long long int i=0;i<len;++i)
    {
        number[i] = (number[i] =='0') ? '1' : '0';
    }
}

void clean_zeroes(char*& number)
{
    long long int len = strlen(number);
    long long int first_index = 0;
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

    for(int j =0;j<new_len;++j)
    {
        clean_result[j]=number[first_index];
        ++first_index;
    }

    delete[] number;
    number = clean_result;
}

