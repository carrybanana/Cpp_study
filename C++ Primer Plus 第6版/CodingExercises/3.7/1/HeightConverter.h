#ifndef _HEIGHT_CONVERTER_H_
#define _HEIGHT_CONVERTER_H_

/**
 * HeightConverter 类用于将身高从英寸转换为英尺和英寸。
 */
class HeightConverter {
private:
    int totalInches; // 总英寸数
    static const int INCHES_PER_FOOT; // 转换因子：1 英尺 = 12 英寸

public:
    /**
     * 构造函数，初始化总英寸数。
     * @param inches 用户输入的总英寸数
     */
    explicit HeightConverter(int inches);

    /**
     * 获取英尺部分。
     * @return 英尺数
     */
    int getFeet() const;

    /**
     * 获取剩余的英寸部分。
     * @return 剩余的英寸数
     */
    int getInches() const;
};

#endif // HEIGHT_CONVERTER_H
