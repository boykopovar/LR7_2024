#pragma once
#include<iostream>
#include<cstring>


bool check_istream();
char* get_bin_line();
char* get_number_line();
void reverse_bits(char*& number);
void clean_zeroes(char*& number);
void longer_number(char*& input_number, long long int target_len);
void char_to_start(char symbol, char*& str);
bool is_bigger(char* number1, char* number2);