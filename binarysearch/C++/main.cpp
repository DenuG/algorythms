#include <vector>
#include <iostream>
#include <cmath>

int binSearch(std::vector<int> vec, int target) 
{
    int low = 0;
    int high = vec.size() - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int guess = vec[mid];
        if(guess == target)
        {
            return mid;
        } else if(guess > target)
        {
            high = mid - 1;
        } else
        {
            low = mid + 1;
        }
    }
    return -1;
}



int main() 
{
    std::cout << binSearch(std::vector<int>{2, 5, 9, 10, 14, 32, 164}, 9) << std::endl;
    std::cout << binSearch(std::vector<int>{2, 5, 9, 10, 14, 32, 164}, 32) << std::endl;
    std::cout << binSearch(std::vector<int>{2, 5, 9, 10, 14, 32, 164}, 164) << std::endl;
    std::cout << binSearch(std::vector<int>{2, 5, 9, 10, 14, 32, 164}, 15) << std::endl;


    return 0;
}