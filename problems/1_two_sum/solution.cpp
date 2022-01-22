#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace quadratic {

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = static_cast<int>(nums.size());
    for (int i = 0; i < size; ++i) {
      int first = nums[i];
      int result = target - first;
      for (int j = i + 1; j < size; ++j) {
        int second = nums[j];
        if (second == result) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

} // namespace quadratic

namespace linear {

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> value_to_index;
    for (int i = 0; i < nums.size(); ++i) {
      int value_to_search = target - nums[i];
      auto it = value_to_index.find(value_to_search);
      if (it == value_to_index.end()) {
        value_to_index[nums[i]] = i;
      } else {
        return {it->second, i};
      }
    }
    return {};
  }
};

} // namespace linear

void Test1() {
  using namespace linear;
  Solution solution;

  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  vector<int> want{0, 1};

  vector<int> got = solution.twoSum(nums, target);
  assert(want == got);
  std::cout << "Test1 passed successfully" << std::endl;
}

void Test2() {
  using namespace linear;
  Solution solution;

  vector<int> nums{3,2,4};
  int target = 6;
  vector<int> want{1, 2};

  vector<int> got = solution.twoSum(nums, target);
  assert(want == got);
  std::cout << "Test2 passed successfully" << std::endl;
}

void Test3() {
  using namespace linear;
  Solution solution;

  vector<int> nums{3, 3};
  int target = 6;
  vector<int> want{0, 1};

  vector<int> got = solution.twoSum(nums, target);
  assert(want == got);
  std::cout << "Test3 passed successfully" << std::endl;
}

void Test4() {
  using namespace linear;
  Solution solution;

  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  vector<int> want{0, 1};

  vector<int> got = solution.twoSum(nums, target);
  assert(want == got);
  std::cout << "Test4 passed successfully" << std::endl;
}

int main() {
  Test1();
  Test2();
  Test3();
  Test4();
  return 0;
}