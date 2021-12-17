#include <stdio.h>
#include <math.h>

int hexToDec(int x)
{
    x = x - 48;
    return (
        x * floor( (-1) * exp(-10) * ( x - 9 ) + 1 ) 
        + ( x - 7 ) * floor( exp(-10) * ( x - 17 ) + 1 )
    );
}

void printDigit(int number, int digit_n)
{
    int digit = (int) (number / pow(10, digit_n - 1)) % 10;
    int digitToAscii = digit + 48;
    putchar(digitToAscii);
}

int main()
{
    int first = getchar();
    int second = getchar();
    int result = hexToDec(first) * 16 + hexToDec(second);
    printDigit(result, 3);
    printDigit(result, 2);
    printDigit(result, 1);
    return 0;
}
