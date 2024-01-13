#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H
#include "BusinessType.h"
#include <string>
#include <ostream>

class BusinessOwner
{
private:
    float _expense;
    float _reveue;
    std::string _registeredBusinessName;
    BusinessType _type;

public:
    BusinessOwner(float expense, float revenue, std::string registeredBusinessName, BusinessType type);

    BusinessOwner() = default;

    BusinessOwner(const BusinessOwner &) = delete;

    BusinessOwner &operator=(const BusinessOwner &) = delete;

    BusinessOwner(BusinessOwner &&) = delete;

    BusinessOwner &operator=(BusinessOwner &&) = delete;

    ~BusinessOwner() = default;

    float expense() const { return _expense; }

    float reveue() const { return _reveue; }

    std::string registeredBusinessName() const { return _registeredBusinessName; }

    BusinessType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_H
