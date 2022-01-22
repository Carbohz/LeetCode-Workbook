#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> res;
    res.reserve(candies.size());
    int max = *max_element(candies.begin(), candies.end());
    for (int candy : candies) {
      res.push_back(candy + extraCandies >= max ? true : false);
    }

    return res;
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    vector<int> candies{2, 3, 5, 1, 3};
    int extra_candies = 3;
    assert((solution.kidsWithCandies(candies, extra_candies) ==
            vector<bool>{true, true, true, false, true}));
  }

  // Example 2
  {
    vector<int> candies{4, 2, 1, 1, 2};
    int extra_candies = 1;
    assert((solution.kidsWithCandies(candies, extra_candies) ==
            vector<bool>{true, false, false, false, false}));
  }

  // Example 3
  {
    vector<int> candies{12, 1, 12};
    int extra_candies = 10;
    assert((solution.kidsWithCandies(candies, extra_candies) ==
            vector<bool>{true, false, true}));
  }
  return 0;
}