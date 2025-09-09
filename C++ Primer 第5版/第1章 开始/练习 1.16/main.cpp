#include <iostream>

int main()
{
    int sum = 0;
    int value = 0;
    std::cout << "请输入一组数据：";
    for( ; std::cin >> value; )
    {
        if (888 == value) {
            std::cout << "输入的数字之和为：" << sum << std::endl;
            break;
        }

        else
            sum += value;
    }

    return 0;
}
