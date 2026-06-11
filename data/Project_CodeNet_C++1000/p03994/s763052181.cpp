#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  string s;
  int k, n;
  cin >> s >> k;
  n = s.length();
  for(int i = 0; i < n - 1; i++) {
    if(s[i] != 'a') {
      if(123 - (int)s[i] <= k) {
        k -= 123 - (int)s[i];
        s[i] = 'a';
      }
    }
  }
  k %= 26;
  while(k--) {
    s[n - 1]++;
    if(s[n - 1] == 123) {
      s[n - 1] = 97;
    }
  }
  cout << s << endl;
  return 0;
}