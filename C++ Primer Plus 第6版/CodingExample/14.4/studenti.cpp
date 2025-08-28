// studentc.cpp -- Student class using containment
#include "studenti.h"
#include <string>
using std::ostream;
using std::istream;
using std::endl;
using std::string;

// public methods
// double Student::Average() const
// {
//     if (ArrayDb::size() > 0)
//         return ArrayDb::sum() / ArrayDb::size();
//     else
//         return 0;
// }
// double Student::Average() const
// {
//     if (((const ArrayDb&)*this).size() > 0)
//         return ((const ArrayDb&)*this).sum() / ((const ArrayDb&)*this).size();
//     else
//         return 0;
// }
double Student::Average() const
{
    if (((const ArrayDb&)*this).size() > 0) // Student是多重继承，ArrayDb 里面有size，string里面也有size
        return (*this).sum() / ((const ArrayDb&)*this).size();
    else
        return 0;
}

const string& Student::Name() const
{
    return (const string&)*this;
}

double& Student::operator[](int i)
{
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// private method
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// friends
// use string version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
    is >> (string&)stu;
    return is;
}

// use string friend getline(ostream&, const string&)
istream& getline(istream& is, Student& stu)
{
    getline(is, (string&)stu);
    return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << (const string&)stu << ":\n";
    stu.arr_out(os);
    return os;
}
