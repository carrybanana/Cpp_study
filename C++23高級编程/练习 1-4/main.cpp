import employee;
import std;

int main()
{
    std::vector<HR::Employee> employees {};

    employees.push_back(
        HR::Employee{
            .firstInitial = 'J',
            .lastInitial = 'W',
            .employeeNumber = 41,
            .salary = 79999,
            .title = HR::Title::SeniorEngineer
        }
    );

    employees.push_back(
        HR::Employee{
            .firstInitial = 'J',
            .lastInitial = 'D',
            .employeeNumber = 133,
            .salary = 64000,
            .title = HR::Title::Engineer
        }
    );

    employees.push_back(
        HR::Employee{
            .firstInitial = 'B',
            .lastInitial = 'P',
            .employeeNumber = 18,
            .salary = 100000,
            .title = HR::Title::Manager
        }
    );

    for (const auto&[firstInitial, lastInitial, employeeNumber, salary, title] : employees) {
        // Print the values of an employee
        std::println("Employee: {}{}", firstInitial, lastInitial);
        std::println("Number: {}", employeeNumber);
        std::println("Salary: ${}", salary);

        switch (title)
        {
            case HR::Title::Engineer:
                std::println("Engineer");
                break;
            case HR::Title::SeniorEngineer:
                std::println("Senior Engineer");
                break;
            case HR::Title::Manager:
                std::println("Manager");
                break;
        }
        std::println("");
    }
}
