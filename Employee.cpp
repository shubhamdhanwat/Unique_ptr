#include "Employee.h"

Employee::Employee(std::string name, EmployeeType type, float salary)
    : _name(name), _type(type), _Salary(salary)
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_name: " << rhs._name
       << " _type: " << static_cast<int>(rhs._type)
       << " _Salary: " << rhs._Salary;
    return os;
}
