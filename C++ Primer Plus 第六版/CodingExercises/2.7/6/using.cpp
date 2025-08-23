#include <iostream>
#include "convert.h"

int main()
{
    Convert convert;
    double num_lightyears(0);
    std::cout << "Enter the number of light years: ";
    std::cin >> num_lightyears;
    double num_ast_units = convert.cvt(num_lightyears);
    std::cout << num_lightyears << " light years = " << num_ast_units << " astronomical units." << std::endl;

    return 0;
}
