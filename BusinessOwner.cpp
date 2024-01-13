#include "BusinessOwner.h"

BusinessOwner::BusinessOwner(float expense, float revenue, std::string registeredBusinessName, BusinessType type)
    : _expense(expense), _reveue(revenue), _registeredBusinessName(registeredBusinessName), _type(type)
{
}
std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs)
{
    os << "_expense: " << rhs._expense
       << " _reveue: " << rhs._reveue
       << " _registeredBusinessName: " << rhs._registeredBusinessName
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}
