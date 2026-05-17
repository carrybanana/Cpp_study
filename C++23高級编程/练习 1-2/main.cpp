import employee;
import std;

int main()
{
    // Create and populate an employee.
    HR::Employee anEmployee{
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 42,
        .salary = 80000,
        .title = HR::Title::SeniorEngineer,
    };

    // Output the values of an employee.
    std::println("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial);
    std::println("Number: {}", anEmployee.employeeNumber);
    std::println("Salary: ${}", anEmployee.salary);
    HR::Employee::say();

    switch (anEmployee.title) {
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
}
