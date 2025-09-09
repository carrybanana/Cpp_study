#include <iostream>

int main()
{
    std::cout << "请输入两个整数：";
    int a(0),b(0);
    std::cin >> a >> b;
    int c = ( a > b ? a : b );
    while ( c >= a || c >= b )
    {
        std::cout << c << " ";
        --c;
    }
    std::cout << std::endl;

    return 0;
}
