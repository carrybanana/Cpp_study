// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;
    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;
public:
    Student() : std::string("NULL Student"), ArrayDb() {}
    explicit Student(const std::string& s) : std::string(s), ArrayDb() {}   // 只用name初始化
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}   // 只用scores初始化
    Student(const std::string& s, int n) : std::string(s), ArrayDb(n) {}    // 使用name和scores初始化
    Student(const std::string& s, const ArrayDb& a) : std::string(s), std::valarray<double>(a) {} //
    Student(const char* str, const double* pd, int n) : std::string(str), ArrayDb(pd, n) {} //
    ~Student() {}

    double Average() const; // 平均数
    const std::string& Name() const;    // 返回姓名
    double& operator[](int i);  // 重载中括号[]
    double operator[](int i) const;

// friend
    // input
    friend std::istream& operator>>(std::istream& is, Student& stu);
    friend std::istream& getline(std::istream& is, Student& stu);

    // output
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif
