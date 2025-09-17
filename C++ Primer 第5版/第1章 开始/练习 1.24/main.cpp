// 编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。

#include "Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    int num = 1;
    std::cout << "请输入若干销售记录： " << std::endl;
    if (std::cin >> trans1) {
        while (std::cin >> trans2) {
            if (compareIsbn(trans1, trans2))
                num++;
            else {
                std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;      // 输出最后一个书的记录。
    }else {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    return 0;
}
