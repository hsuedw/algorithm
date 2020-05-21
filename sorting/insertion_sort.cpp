#include <iostream>
#include <string>
#include <vector>
using namespace std;

void InsertionSort(std::vector<int>& list) {
    const int sz = static_cast<int>(list.size());
    for (int i = 1; i < sz; i++) {
        int key = list[i];
        int j = i - 1;
        while (key < list[j] && j >= 0) {
            list[j + 1] = list[j];
            j--;
        } // end of while-loop
        list[j + 1] = key;
    } // end of for-loop
    return;
}

int main()
{
    std::vector<int> list = {4, 6, 2, 0, 9, 1, 5, 7, 8, 3};
    
    InsertionSort(list);
    
    std::cout << "[";
    for (auto& i : list) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}

