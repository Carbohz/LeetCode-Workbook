#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    vector<vector<int*>> diag_view = GetDiagonalView(mat);

    for (vector<int*>& v : GetDiagonalView(mat)) {
      std::sort(v.begin(), v.end(), [](int* a, int* b) { return *a < *b; });
    }

    return mat;
  }

private:
  vector<vector<int*>> GetDiagonalView(vector<vector<int>>& mat) {
    const int m = static_cast<int>(mat.size());
    const int n = static_cast<int>(mat[0].size());
    vector<vector<int*>> diag_mat_view(static_cast<int64_t>(m) + n - 1);

    for (int k = m - 1; k >= 0; --k) {
      int i = k;
      int j = 0;
      while (i <= m - 1) {
        diag_mat_view[static_cast<int64_t>(m) - k - 1].push_back(&mat[i][j]);
        ++i;
        ++j;
      }
    }

    for (int k = 1; k <= n - 1; ++k) {
      int i = 0;
      int j = k;
      while (j <= n - 1) {
        diag_mat_view[static_cast<int64_t>(k) + m - 1].push_back(&mat[i][j]);
        ++i;
        ++j;
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