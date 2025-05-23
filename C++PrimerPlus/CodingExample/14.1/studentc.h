// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <istream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;
    std::ostream& arr_out(std::ostream& os) const;
public:
    Student() : name("NULL Student"), scores() {}
    explicit Student(const std::string& s) : name(s), scores() {}   // 只用name初始化
    explicit Student(int n) : name("Nully"), scores(n) {}   // 只用scores初始化
    Student(const std::string& s, int n) : name(s), scores(n) {}    // 使用name和scores初始化
    Student(const std::string& s, const ArrayDb& a) : name(s), scores(a) {} //
    Student(const char* str, const double* pd, int n) : name(str), scores(pd, n) {} //
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
