#include <iostream>
#include <string>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        os << el << ' ';
    }
    return os;
}

auto MyPartition(auto first, auto last) {
    auto pivotIt = last - 1;
    auto aIt = first - 1;
    auto bIt = first;
    
    for (;bIt != pivotIt; bIt++) {
        if (*bIt < *pivotIt) {
            aIt++;
            std::swap(*aIt, *bIt);
        }
    } // end of for-loop
    aIt++;
    std::swap(*aIt, *pivotIt);
    return aIt;
}

void QuickSort(auto first, auto last) {
    if (first == last)
        return;
    auto pivoIt = MyPartition(first, last);
    QuickSort(first, pivoIt);
    QuickSort(pivoIt + 1, last);
}

int main()
{
    std::vector<int> vec = {9, 3, 6, 1, 7, 4, 8, 5, 2, 0, 10, 32, 12, 23, 45, 67};
    QuickSort(std::begin(vec), std::end(vec));
    std::cout << vec << std::endl;
    return 0;
}

