export module employee;

import std;

namespace HR
{
    export enum class Title {
        Engineer,
        SeniorEngineer,
        Manager,
    };

    export struct Employee {
        std::string firstInitial;
        std::string lastInitial;
        int employeeNumber;
        int salary;
        Title title;

        static void say();
    };
}