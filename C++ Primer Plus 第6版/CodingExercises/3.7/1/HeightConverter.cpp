#include "HeightConverter.h"

// 定义转换因子：1 英尺 = 12 英寸
const int HeightConverter::INCHES_PER_FOOT = 12;

/**
 * 构造函数，初始化总英寸数。
 * @param inches 用户输入的总英寸数
 */
HeightConverter::HeightConverter(int inches)
    : totalInches(inches) {}

/**
 * 获取英尺部分。
 * @return 英尺数
 */
int HeightConverter::getFeet() const {
    return totalInches / INCHES_PER_FOOT; // 计算英尺数
}

/**
 * 获取剩余的英寸部分。
 * @return 剩余的英寸数
 */
int HeightConverter::getInches() const {
    return totalInches % INCHES_PER_FOOT; // 计算剩余的英寸数
}
