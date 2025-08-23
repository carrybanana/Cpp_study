//
// Created by CarryBanana on 24-3-23.
//

#include <iostream>

int main() {
    using namespace std;
    constexpr int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];
    cout << "Enter your name:\n";
    cin.get(name, Arsize).get();
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, Arsize);
    cin.get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}