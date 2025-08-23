#include <iostream>
#include "HeightConverter.h"

int main() {
    int inputInches; // 用户输入的总英寸数

    // 提示用户输入身高（英寸）
    std::cout << "请输入您的身高（英寸）: ____\b\b\b\b";
    std::cin >> inputInches;

    // 创建 HeightConverter 对象，传入用户输入的总英寸数
    HeightConverter converter(inputInches);

    // 获取并显示转换后的身高
    std::cout << "您的身高是: "
              << converter.getFeet() << " 英尺 " // 输出英尺部分
              << converter.getInches() << " 英寸" // 输出剩余的英寸部分
              << std::endl;

    return 0; // 程序正常结束
}
