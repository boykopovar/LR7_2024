#include<iostream>

#include"task_1.h"
#include"../global_utils.h"

//O(len)
char* from_add_to_reverse(char* number)
{
    if(number[0] == '0') return number;

    number = minus_one(number);
    return number;
}

//O(len)
char* minus_one(char* number)
{
    long long int len = strlen(number);
    for(long long int i = len-1;i>=0;--i)
    {
        if(number[i]=='1')
        {
            number[i]='0';
            break;
        }
        else //number[i] == 0
        {
            number[i] = '1';
        }
    }
    return number;
}

