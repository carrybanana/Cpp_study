#include <iostream>

int main()
{
    // std::cout << "Please enter your first name (followed by 'enter'):\n";
    std::cout << "Enter the name of the person you want to write to\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Enter the name of the friend\n";
    std::string friend_name;
    std::cin >> friend_name;
    std::cout << "Enter the friend sex(man enter 'm', woman enter 'f')\n";
    char friend_sex{0};
    std::cin >> friend_sex;
    // std::cout << "Hello, " << first_name << "\n";
    std::cout << "Dear " << first_name << ",\n" << "\tHow are you? I am fine. I miss you.\n" << "\tHave you seen " << friend_name << " lately?";
    if('m' == friend_sex)
        std::cout << " If you see " << friend_name << " please ask him to call me.";
    else if('f' == friend_sex)
        std::cout << " if you see " << friend_name << " please ask her to call me.";
    else
        std::cout << " error!";

    return 0;
}
