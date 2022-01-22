#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    string answer;
    uint64_t curr_dot_pos = address.find('.');
    uint64_t prev_dot_pos = 0u;
    while (curr_dot_pos != std::string::npos) {
      answer += address.substr(prev_dot_pos,
                               curr_dot_pos - prev_dot_pos); // [prev; curr)
      answer += "[.]"s;
      prev_dot_pos = curr_dot_pos + 1;
      curr_dot_pos = address.find('.', curr_dot_pos + 1u);
    }
    answer += address.substr(prev_dot_pos, curr_dot_pos - prev_dot_pos);
    return answer;
  }
};

int main() {
  Solution solution;

  // Example 1
  {
    string address = "1.1.1.1"s;
    string answer = solution.defangIPaddr(address);
    assert(answer == "1[.]1[.]1[.]1"s);
  }

  // Example 2
  {
    string address = "255.100.50.0"s;
    string answer = solution.defangIPaddr(address);
    assert(answer == "255[.]100[.]50[.]0"s);
  }

  return 0;
}