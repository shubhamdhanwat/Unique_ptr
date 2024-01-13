#ifndef DATAMODELLER_H
#define DATAMODELLER_H
#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include <memory>
#include <vector>
#include <ostream>

using BusinessPointer = std::unique_ptr<BusinessOwner>;
using EMpPointer = std::unique_ptr<Employee>;
using Vtype = std::variant<BusinessPointer, EMpPointer>;
class DataModeller
{
private:
    Vtype _instance;
    std::vector<float> _goodsPrices;

public:
    DataModeller(Vtype v, const std::vector<float>& prices);
    void operator()();

    DataModeller() = default;

    DataModeller(const DataModeller &) = delete;

    DataModeller &operator=(const DataModeller &) = delete;

    DataModeller(DataModeller &&) = delete;

    DataModeller &operator=(DataModeller &&) = delete;

    ~DataModeller() = default;

    std::vector<float> goodsPrices() const { return _goodsPrices; }

    const Vtype &instance() const { return _instance; }

    friend std::ostream &operator<<(std::ostream &os, const DataModeller &rhs);
};

#endif // DAYAMODELLER_H
