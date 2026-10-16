#include "holiday.h"
#include <array>

namespace kwonyonje2649061
{
    void printHolidayArray(const holiday a[], const int n)
    {
        for (int i=0; i<n; ++i)
            std::cout << a[i];
        std::cout << std::endl;
    }
}

int main()
{
    const int n{4};
    using namespace kwonyonje2649061;
    holiday a[n]; 
    a[0] = holiday{"christmas", {12, 25}, false};
    a[0].print();
    a[1].setName("new year day"); a[1].setD(dayOfYear{1,1}); a[1].setparkingEnforcement(false);
    a[2].input(); a[2].print();
    std::cin >> a[3];

    std::array<holiday, n> arr;
    for (int i =0; i< arr.size() ; ++i)
        arr.at(i) = a[i]; 
    for (const auto& arri : arr)
        arri.print();

    return 0;
}