#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

namespace dumb {

class Solution {
public:
  int romanToInt(string s) {
    std::unordered_map<std::string, int> letter_to_value{
        {"I", 1},    {"IV", 4},  {"IX", 9},  {"V", 5},   {"X", 10},
        {"XL", 40},  {"XC", 90}, {"L", 50},  {"C", 100}, {"CD", 400},
        {"CM", 900}, {"D", 500}, {"M", 1000}};

    std::array<char, 3> specific_chars{'I', 'X', 'C'};

    // I -> V, X
    std::array<char, 2> specific_chars_for_I{'V', 'X'};
    // X -> L, C
    std::array<char, 2> specific_chars_for_X{'L', 'C'};
    // C -> D, M
    std::array<char, 2> specific_chars_for_C{'D', 'M'};

    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (!isSpecificChar(c, specific_chars)) {
        result += letter_to_value[std::string(1, c)];
      } else {
        if (i + 1 == s.size()) {
          // last char in string
          result += letter_to_value[std::string(1, c)];
        } else {
          switch (c) {
          case 'I':
            if (!isSpecificChar(s[i + 1], specific_chars_for_I)) {
              result += letter_to_value[std::string(1, c)];
            } else {
              std::string combo = std::string(1, c) + s[i + 1];
              result += letter_to_value[combo];
              ++i;
            }
            break;
          case 'X':
            if (!isSpecificChar(s[i + 1], specific_chars_for_X)) {
              result += letter_to_value[std::string(1, c)];
            } else {
              std::string combo = std::string(1, c) + s[i + 1];
              result += letter_to_value[combo];
              ++i;
            }
            break;
          case 'C':
            if (!isSpecificChar(s[i + 1], specific_chars_for_C)) {
              result += letter_to_value[std::string(1, c)];
            } else {
              std::string combo = std::string(1, c) + s[i + 1];
              result += letter_to_value[combo];
              ++i;
            }
            break;
          }
        }
      }
    }
    return result;
  };

  template <size_t N>
  bool isSpecificChar(char c, std::array<char, N> specific_chars) {
    for (char s : specific_chars) {
      if (s == c) {
        return true;
      }
    }
    return false;
  };
};

} // namespace dumb

namespace optimal {

class Solution {
public:
  int romanToInt(string s) {
    std::unordered_map<char, int> roman_to_integer{
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      int current_integer = roman_to_integer[s[i]];
      if (i + 1 < s.size() && current_integer < roman_to_integer[s[i + 1]]) {
        result -= current_integer;
      } else {
        result += current_integer;
      }
    }
    return result;
  };
};

} // namespace optimal

using namespace optimal;

void Test1() {
  Solution solution;

  std::string input = "III";
  int want = 3;

  int got = solution.romanToInt(input);
  assert(want == got);
  std::cout << "Test1 passed successfully" << std::endl;
}

void Test2() {
  Solution solution;

  std::string input = "LVIII";
  int want = 58;

  int got = solution.romanToInt(input);
  assert(want == got);
  std::cout << "Test2 passed successfully" << std::endl;
}

void Test3() {
  Solution solution;

  std::string input = "MCMXCIV";
  int want = 1994;

  int got = solution.romanToInt(input);
  assert(want == got);
  std::cout << "Test3 passed successfully" << std::endl;
}

int main() {
  Test1();
  Test2();
  Test3();
  return 0;
}