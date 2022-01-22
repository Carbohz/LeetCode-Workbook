#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1u) {
      return false;
    }

    std::sort(nums.begin(), nums.end());
    for (size_t i = 0u; i < nums.size() - 1; ++i) {
      if (!(nums[i + 1] > nums[i])) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    vector<int> input{1, 2, 3, 1};
    assert(solution.containsDuplicate(input));
  }

  // Example 2
  {
    vector<int> input{1, 2, 3, 4};
    assert(!solution.containsDuplicate(input));
  }

  // Example 3
  {
    vector<int> input{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    assert(solution.containsDuplicate(input));
  }
  return 0;
}