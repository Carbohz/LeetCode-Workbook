#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());

    return static_cast<int>(nums.size());
  }
};

void Test1() {
  // Example 1
  Solution solution;
  vector<int> input{1, 1, 2};
  assert(solution.removeDuplicates(input) == 2);
  assert((input == vector<int>{1, 2}));
  std::cout << "Test1 passed successfully" << std::endl;
}

void Test2() {
  // Example 2
  Solution solution;
  vector<int> input{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  assert(solution.removeDuplicates(input) == 5);
  assert((input == vector<int>{0, 1, 2, 3, 4}));
  std::cout << "Test2 passed successfully" << std::endl;
}

int main() {
  Test1();
  Test2();
  return 0;
}
