#include "Functionalities.h"
#include "Employee.h"
#include <memory>
#include <vector>
#include "DataModeller.h"

void CreateObjects(Container &data)
{

    // std::unique_ptr<DataModeller> ptr=std::make_unique<DataModeller>(
    //     //instance
    //     std::make_unique<Employee>(
    //         "rahul",
    //         EmployeeType::REGULAR,
    //         780000.0f),
    //         //vector of floats
    //         std::vector<float>{19.21f, 145.31,204.5f}
    // );

    data.emplace_back(
        std::make_unique<DataModeller>(
            // instance
            std::make_unique<Employee>(
                "rahul",
                EmployeeType::REGULAR,
                780000.0f),
            // vector of floats
            std::vector<float>{19.21f, 145.31, 204.5f}));

    data.emplace_back(
        std::make_unique<DataModeller>(
            // instance
            std::make_unique<BusinessOwner>(
                10000000.0f,
                134000.0f,
                "xyz Corporation",
                BusinessType::MNC),
            // vector of floats
            std::vector<float>{19.21f, 145.31, 204.5f}));
}

/*
    This funtion will accept a container of datamodeller pointer
    for each pointer , perform the following
    a)capture the instance reference
    b)use hold _alternative to verify which type of pointer is present in the _instance
    c)if pointer is of type businerssowner
        1)use std::get to fetch businessowner (this will be safe because if has been checked before )
        2)use the feched pointer tin businedssowner to calculate tax or business
     else when pointer is of type employee
        1)use std::Get to fetech employeepointer
        2)use the fetched pointer to fetch type of employee
        3)if type is regulat tax is 10% else it should be 20% of salary
*/
void CalculateTaxPayable(const Container &data)
{
    for (const dataPointer &ptr : data)
    {
        const Vtype &val = ptr->instance();
        if (std::holds_alternative<BusinessPointer>(val))
        {
            const BusinessPointer &p = std::get<BusinessPointer>(val);
            std::cout << "Tax is " << 0.1f * (p->reveue() - p->expense());
        }
        else
        {
            const EMpPointer &p = std::get<EMpPointer>(val);
            if (p->type() == EmployeeType::REGULAR)
            {
                std::cout << "Tax is 10% " << 0.1f * p->salary() << "\n";
            }
            else
            {
                std::cout << "Tax is 20% " << 0.2f * p->salary() << "\n";
            }
        }
    }
}
/*

*/
void CallParenOperator(const Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("data is empty :");
    }
    else
    {
        for (const dataPointer &ptr : data)
        {
            ptr->operator()();
        }
    }
}