// 编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。

#include "Sales_item.h"

int main()
{
    Sales_item total, trans;
    std::cout << "请输入几条 ISBN 相同的销售记录：" << std::endl;
    if (std::cin >> total) {
        while (std::cin >> trans) {
            if (compareIsbn(total, trans))
                total += trans;
            else {
                std::cout << "ISBN 不同" << std::endl;
                return -1;
            }
        }
        std::cout << "汇总信息：ISBN、售出本数、销售额和平均售价为 " << total << std::endl;
    }
    else {
        std::cout << "没有数据" << std::endl;
        return -1;
    }

    return 0;
}
