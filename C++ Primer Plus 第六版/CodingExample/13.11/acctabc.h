// acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <ios>
#include <iostream>
#include <string>

//Abstract Base Class
class AcctABC
{
private:
    std::string fullName;   //账户名称
    long acctNum;   //账户号码
    double balance; //余额
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string& FullName() const { return fullName; }    //显示账户名称
    long AcctNum() const { return acctNum; }    //显示账户号码
    Formatting SetFormat() const;
    void Restore(Formatting& f) const;
public:
    AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0); //构造函数
    void Deposit(double amt);   //存钱
    virtual void Withdraw(double amt) = 0;  //纯虚函数,取钱
    double Balance() const { return balance; }  //显示余额
    virtual void ViewAcct() const = 0;  //纯虚函数,显示账户信息
    virtual ~AcctABC() {}
};

// Brass Account Class
class Brass : public AcctABC
{
public:
    Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {}
    virtual void Withdraw(double amt);  //取钱
    virtual void ViewAcct() const;  //显示账户信息
    virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
    double maxLoan; //透支上限
    double rate;    //透支利率
    double owesBank;    //透支总额
public:
    BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif
