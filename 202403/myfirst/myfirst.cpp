//
// Created by CarryBanana on 24-3-15.
//

#include <climits>
#include <cmath>
#include <iostream>


int main() {
    // using namespace std;
    // using std::endl;
    // using std::cout;
    std::cout << "Come up and C++ me some time." << std::endl;
    std::cout << "You won't regret it!" << std::endl;

    using namespace std;
    double area;
    cout << "enter the floor area, in suquare feet, of your home: ";
    cin >> area;
    double side = sqrt(area);
    cout << "that's the equivalent of a square " << side << " feet to the side." <<endl;
    cout << "how fascinating!" << endl;
    cout << "long long : " << ULLONG_MAX << endl;
    cout << "long : " << ULONG_MAX << endl;
    cout << "int : " << UINT_MAX << endl;
    cout << "short : " << USHRT_MAX << endl;

    cout << "--------------------";
    int a(5);
    int b{6};
    cout << endl;
    cout << a << endl;
    cout << b << endl;


    return 0;
}
