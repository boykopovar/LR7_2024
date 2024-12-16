#include"task_4.h"


bool is_divisible(const char* number, long long int div)
{
    long long int current_part = 0;
    for(long long int i = 0;number[i]!='\0';++i)
    {
        long long int current_digit = number[i] & 15; //number[i]-'0'
        current_part = (current_part<<1) + (current_part<<3) + current_digit; //*=10 + c_d

        while(current_part>=div) // O(log(current_part / div))
        {
            long long int buf = div;
            while(2*buf<=current_part) //O(log(current_part / buf)
            {
                buf<<=1; // *=2
            }
            current_part+=(~buf+1); // -=buf
        }
    }
    return current_part==0;
}


