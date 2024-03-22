//
// Created by CarryBanana on 24-3-22.
//

#include <iostream>
#include <cstring>

int main() {
    using namespace std;
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";
    cout << "Howdy! I'm " << name2;
    cout << " what's your name?\n";
    cin >> name1;
    cout << "well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letter and is strode in an array of " << sizeof(name1) <<" bytes.\n";
    cout << "your initial is " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;

    return 0;
}
