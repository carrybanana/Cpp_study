#include "convert.h"
#include <iostream>

int main()
{
    int hours(0), minutes(0);
    std::cout << "Enter the number of hours:";
    std::cin >> hours;
    std::cout << "Enter the number of minutes:";
    std::cin >> minutes;
    show(hours, minutes);

    return 0;
}
