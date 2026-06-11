#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n;
  std::string s, s2;
  std::cin >> n >> s >> s2;
  for(int i = 0; i <= n; i++) {
    int valid = 1;
    for(int j = i; j < n; j++)
      if(s[j] != s2[j - i])
        valid = 0;
    
    if(valid == 1) {
      std::cout << n + i;
      return 0;
    }
  }
  return 0;
}
