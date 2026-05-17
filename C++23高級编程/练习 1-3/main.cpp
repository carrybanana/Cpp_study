import employee;
import std;

int main()
{
    // Create and populate an employee.
    constexpr HR::Employee employee1 {
        .firstInitial = 'J',
        .lastInitial = 'W',
        .employeeNumber = 42,
        .salary = 80000,
        .title = HR::Title::SeniorEngineer
    };

    constexpr HR::Employee employee2 {
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 133,
        .salary = 64000,
        .title = HR::Title::Engineer
    };

    constexpr HR::Employee employee3 {
        .firstInitial = 'B',
        .lastInitial = 'P',
        .employeeNumber = 18,
        .salary = 100000,
        .title = HR::Title::Manager
    };

    std::array employees {
        employee1,
        employee2,
        employee3
    };

    for (const auto&[firstInitial, lastInitial, employeeNumber, salary, title] : employees) {
        // Print the values of an employee
        std::println("Employee: {}{}", firstInitial, lastInitial);
        std::println("Number: {}", employeeNumber);
        std::println("Salary: ${}", salary);

        switch (title)
        {
            using enum HR::Title;

            case Engineer:
                std::println("Engineer");
                break;
            case SeniorEngineer:
                std::println("Senior Engineer");
                break;
            case Manager:
                std::println("Manager");
                break;
        }
        std::println("");
    }
}
