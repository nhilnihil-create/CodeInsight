#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::string s;
  std::cin >> s;
  std::string s2;
  for(int i = 0; i < s.size(); i++) {
    if(0 == s2.size() || s2.back() == 'T')
      s2 += s[i];
    else if(s[i] == 'T') {
      s2.pop_back();
    } else
      s2.push_back(s[i]);
  }
  std::cout << s2.size();
  return 0;
}
