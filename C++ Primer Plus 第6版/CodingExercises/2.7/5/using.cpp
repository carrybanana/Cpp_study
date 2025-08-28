#include <iostream>
#include "convert.h"

int main()
{
    Convert convert;
    double num_Ct(0);
    std::cout << "Please enter a Celsius value: ";
    std::cin >> num_Ct;
    double num_Ft = convert.Ct_Ft(num_Ct);
    std::cout << num_Ct << " degrees Celsius is " << num_Ft << " degrees Fahrenheit." << std::endl;

    return 0;
}
