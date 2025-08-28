#include "long_yard.h"
#include <iostream>

int main()
{
    long_yard longtoyard;
    int num_long(0);
    std::cout << "请输入距离（以 long 为单位）:";
    std::cin >> num_long;
    double num_yard = longtoyard.LongToYard(num_long);
    std::cout << "转换后的码为：" << num_yard << std::endl;

    return 0;
}
