#include <iostream> // Gives us std::cout (output) and std::cin (input).
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
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
    return 0; // Tells the operating system the program finished successfully.
}
