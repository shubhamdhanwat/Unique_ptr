#include "DataModeller.h"

DataModeller::DataModeller(Vtype v, const std::vector<float> &prices)
    : _instance(std::move(v)), _goodsPrices(prices)
{
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
