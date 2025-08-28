#include <iostream>

int main()
{
    // std::cout << "Please enter your first name (followed by 'enter'):\n";
    std::cout << "Enter the name of the person you want to write to\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "输入收信人的年龄：";
    int age{0};
    std::cin >> age;
    if (age <= 0 || age >= 110) {
        std::cout << "you'r kidding!";
        return -1;
    }
    std::cout << "Enter the name of the friend\n";
    std::string friend_name;
    std::cin >> friend_name;
    std::cout << "Enter the friend sex(man enter 'm', woman enter 'f')\n";
    char friend_sex{0};
    std::cin >> friend_sex;
    // std::cout << "Hello, " << first_name << "\n";
    std::cout << "Dear " << first_name << ",\n" << "\tHow are you? I am fine. I miss you.\n";
    std::cout << "\tI hear you just had a birthday and you are " << age << " years old.";
    if (age < 12)
        std::cout << " Next year you will be " << age + 1 << ".\n";
    else if (age == 17)
        std::cout << " Next year you will be able to vote.\n";
    else if (age > 70)
        std::cout << " I hope you are enjoying retirement.\n";
    else
        std::cout << "\n";

    std::cout << "\tHave you seen " << friend_name << " lately?";
    if ('m' == friend_sex)
        std::cout << " If you see " << friend_name << " please ask him to call me.";
    else if ('f' == friend_sex)
        std::cout << " If you see " << friend_name << " please ask her to call me.";
    else
        std::cout << " error!";

    std::cout << std::endl;
    std::cout << "\tYours sincerely,  " << "JiangYongling.";

    return 0;
}
