#include <iostream>

int mod_prime(int num, int prime) {
    int result = 0;

    for (int i = 31; i >= 0; --i) {
        result <<= 1;
        result |= (num >> i) & 1;
        if (result >= prime) {
            result -= prime;
        }
    }

    return result;
}


