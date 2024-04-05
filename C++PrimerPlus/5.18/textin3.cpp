// #include <iostream>

// int main()
// {
//     using namespace std;
//     char ch;
//     int count = 0;
//     // cout << "Enter characters; enter # to quit:\n";
//     cin.get(ch);
//     // while (cin.fail() == false)
//     while (!cin.fail())
//     {
//         cout << ch;
//         ++count;
//         cin.get(ch);
//     }
//     cout << endl << count << " characters read\n";

//     return 0;
// }


// #include <iostream>

// int main()
// {
//     using namespace std;
//     char ch;
//     cin.get(ch);
//     int count = 0;
//     while (cin)
//     {
//         cout << ch;
//         ++count;
//         cin.get(ch);
//     }
//     cout << endl << count << " characters read\n";

//     return 0;
// }


#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    while (cin.get(ch))
    {
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}