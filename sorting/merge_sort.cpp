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

void InplaceMerge(auto first, auto middle, auto last) {
    std::vector<int> leftSubList(first, middle);
    std::vector<int> rightSubList(middle, last);
    
    auto leftIt = std::begin(leftSubList);
    auto rightIt = std::begin(rightSubList);
    auto front = first;
    
    while (leftIt != std::end(leftSubList) &&
           rightIt != std::end(rightSubList)) {
        if (*leftIt < *rightIt) {
            *front = *leftIt;
            leftIt++;
        } else {
            *front = *rightIt;
            rightIt++;
        }
        front++;
    } // end of while-loop
    
    while (leftIt != std::end(leftSubList)) {
        *front = *leftIt;
        leftIt++;
        front++;
    } // end of while-loop
    
    while (rightIt != std::end(rightSubList)) {
        *front = *rightIt;
        rightIt++;
        front++;
    } // end of while-loop
}

void MergeSort(auto first, auto last) {
    if (first + 1 == last) {
        return;
    }
    auto middle = first + (last - first) / 2;
    MergeSort(first, middle);
    MergeSort(middle, last);
    InplaceMerge(first, middle, last);
}

int main()
{
    std::vector<int> vec = {9, 3, 6, 1, 7, 4, 8, 5, 2};
    MergeSort(std::begin(vec), std::end(vec));
    
    std::cout << vec << std::endl;

    return 0;
}

