#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
std::map<char, int> mp;

int main() {
  std::string s;
  std::cin >> s;
  for(int i = 0; i < s.size(); i++)
    mp[s[i]]++;

  if(0 < mp['N'] && 0 == mp['S'])
    std::cout << "No";
  else if(0 == mp['N'] && 0 < mp['S'])
    std::cout << "No";
  else if(0 < mp['E'] && 0 == mp['W'])
    std::cout << "No";
  else if(0 == mp['E'] && 0 < mp['W'])
    std::cout << "No";
  else
    std::cout << "Yes";
  return 0;
}
