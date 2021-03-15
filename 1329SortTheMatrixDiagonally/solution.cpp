#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    vector<vector<int>> res = GetDiagonalView(mat);

    return res;
  }

private:
  vector<vector<int>> GetDiagonalView(const vector<vector<int>>& mat) {
    vector<vector<int>> diag_mat_view(mat.size() + mat[0].size() - 1);
    for (size_t i = 0; i < mat.size(); ++i) {
      for (size_t j = 0; j <= i; ++j) {
        diag_mat_view[j].push_back(mat[i][j]);
      }
    }

    for (size_t i = 0; i < mat.size(); ++i) {
      for (size_t j = i + 1; j < mat[0].size(); ++j) {
        diag_mat_view[j + 2].push_back(mat[i][j]);
      }
    }

    return diag_mat_view;
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    vector<vector<int>> mat{{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    vector<vector<int>> output = {{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}};
    vector<vector<int>> answer = solution.diagonalSort(mat);
    assert(answer == output);
  }

  // Example 2
  {
    vector<vector<int>> mat{{11, 25, 66, 1, 69, 7},
                            {23, 55, 17, 45, 15, 52},
                            {75, 31, 36, 44, 58, 8},
                            {22, 27, 33, 25, 68, 4},
                            {84, 28, 14, 11, 5, 50}};
    vector<vector<int>> output = {{5, 17, 4, 1, 52, 7},
                                  {11, 11, 25, 45, 8, 69},
                                  {14, 23, 25, 44, 58, 15},
                                  {22, 27, 31, 36, 50, 66},
                                  {84, 28, 75, 33, 55, 68}};
    vector<vector<int>> answer = solution.diagonalSort(mat);
    assert(answer == output);
  }

  return 0;
}