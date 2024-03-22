//
// Created by CarryBanana on 24-3-22.
//

#include <iostream>

int main() {
    using namespace std;
    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];
    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some dessert " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}