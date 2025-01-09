#include "ytom.h"
#include <iostream>
int main()
{
    printytom yourage;
    int in_age(0);
    std::cout << "Enter your age : ";
    std::cin >> in_age;
    yourage.yeartom(in_age);

    return 0;
}
