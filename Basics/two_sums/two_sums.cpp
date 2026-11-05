#include <iostream> // Gives us std::cout (output) and std::cin (input).
#include <algorithm>
#include <utility>
#include <vector>
// Every C++ program starts running inside the main function.
int main() {
    // Statements usually end with a semicolon (;).
    std::cout << "Hello, world!\n";

    // Declare a variable: type name = value;
    int number = 0;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "You entered: " << number << '\n';

    // Write your practice code here.
    class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        std::sort(indexedNums.begin(), indexedNums.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                      if (a.first == b.first) {
                          return a.second < b.second;
                      }
                      return a.first < b.first;
                  });

        int s = 0;
        int e = indexedNums.size() - 1;
        while (s < e) {
            int sum = indexedNums[s].first + indexedNums[e].first;

            if (sum < target) {
                ++s;
            } else if (sum > target) {
                --e;
            } else {
                return {indexedNums[s].second, indexedNums[e].second};
            }
        }

        return {};
    }
};
    return 0; // Tells the operating system the program finished successfully.
}
