#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> result;
    result.reserve(nums.size());
    int sum = 0;
    for (size_t i = 0u; i < nums.size(); ++i) {
      sum += nums[i];
      result.push_back(sum);
    }
    return result;
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    vector<int> input{1, 2, 3, 4};
    assert((solution.runningSum(input) == vector<int>{1, 3, 6, 10}));
  }

  // Example 2
  {
    vector<int> input{1, 1, 1, 1, 1};
    assert((solution.runningSum(input) == vector<int>{1, 2, 3, 4, 5}));
  }

  // Example 3
  {
    vector<int> input{3, 1, 2, 10, 1};
    assert((solution.runningSum(input) == vector<int>{3, 4, 6, 16, 17}));
  }
  return 0;
}