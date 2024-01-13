#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string.h>
#include "EmployeeType.h"

class Employee
{
private:
    std::string _name;
    EmployeeType _type;
    float _Salary;

public:
    Employee(std::string name, EmployeeType type, float salary);
    
    Employee() = default;

    Employee(const Employee &) = delete;

    Employee &operator=(const Employee &) = delete;

    Employee(Employee &&) = delete;

    Employee &operator=(Employee &&) = delete;

    ~Employee() = default;

    std::string name() const { return _name; }

    EmployeeType type() const { return _type; }

    float salary() const { return _Salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
