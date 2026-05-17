export module employee;
export namespace HR
{
    enum class Title {
        Engineer,
        SeniorEngineer,
        Manager,
    };

    struct Employee {
        char firstInitial;
        char lastInitial;
        int employeeNumber;
        int salary;
        Title title;

        static void say();
    };
}