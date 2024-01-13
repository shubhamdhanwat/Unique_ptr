#include <iostream>
#include <thread>
#include "Functionalities.h"
#include <array>

int main()

{
    Container data;
    std::array<std::thread, 3> arr;

    arr[0] = std::thread(CreateObjects, std::ref(data));
    arr[0].join();

    arr[1] = std::thread(CalculateTaxPayable, std::ref(data));
    arr[2] = std::thread(CallParenOperator, std::ref(data));
    arr[1].join();
    arr[2].join();
}