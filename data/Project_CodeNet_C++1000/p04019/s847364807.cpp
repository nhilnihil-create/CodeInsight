// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

// DELETE the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

const int N_MAX = 100003;
char s[N_MAX];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  std::map<char, int> mp;
  mp['N'] = 0, mp['S'] = 1, mp['E'] = 2, mp['W'] = 3;
  int ext[4] = {0, 0, 0, 0};
  for (int i = 1; i <= n; ++i)
    ext[mp[s[i]]] = 1;
  printf(((ext[0] ^ ext[1]) == 0) && ((ext[2] ^ ext[3]) == 0) ?
         "Yes\n" : "No\n");
  return 0;
}
