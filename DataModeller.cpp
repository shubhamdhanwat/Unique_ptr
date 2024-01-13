#include "DataModeller.h"

DataModeller::DataModeller(Vtype v, const std::vector<float> &prices)
    : _instance(std::move(v)), _goodsPrices(prices)
{
}

std::ostream &operator<<(std::ostream &os, const DataModeller &rhs)
{
    os << "_instance: ";
    std::visit(
        [&](auto &&val)
        { os << *val; },
        rhs._instance);
    for (float val : rhs._goodsPrices)
    {
        os << val << "\t";
    }
    return os;
}

void DataModeller::operator()()
{
    if (_goodsPrices.empty())
    {
        throw std::runtime_error("NOt found");
    }

    float total = 0.0f;

    for (float val : _goodsPrices)
    {
        total += val;
    }
    std::cout << "\nAverage  value is : " << total / _goodsPrices.size() << "\n";
}
