#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // int removeDuplicates(vector<int>& nums) {
  //  int current = *nums.begin();
  //  int previous = current;
  //  for (auto it = nums.begin(); it != nums.end();) {
  //    if (*it != previous) {
  //      current = *it;
  //    }

  //    if (*it == current) {
  //      current = *it;
  //      it = nums.erase(it);
  //    }
  //    ++it;
  //  }
  //  return static_cast<int>(nums.size());
  //}

  // int removeDuplicates(vector<int>& nums) {
  //  if (nums.empty()) {
  //    return 0;
  //  }

  //  int current = *nums.begin();
  //  vector<int> unique_nums;
  //  unique_nums.reserve(nums.size());
  //  unique_nums.push_back(*nums.begin());

  //  for (auto it = next(nums.begin()); it != nums.end(); ++it) {
  //    if (*it != current) {
  //      unique_nums.push_back(*it);
  //    }
  //    current = *it;
  //  }

  //  nums.clear();
  //  for (int& item : unique_nums) {
  //    nums.push_back(item);
  //  }
  //  return static_cast<int>(nums.size());
  //}

  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());

    return static_cast<int>(nums.size());
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    vector<int> input{1, 1, 2};
    assert(solution.removeDuplicates(input) == 2);
    assert((input == vector{1, 2}));
  }

  // Example 2
  {
    vector<int> input{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    assert(solution.removeDuplicates(input) == 5);
    assert((input == vector{0, 1, 2, 3, 4}));
  }
  return 0;
}