#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  int res = (int)s.size();
  for (char c: s) {
    int tmp = 0;
    for (int i=0; i<s.size();) {
      int j = i;
      while (j<s.size()&&!((s[j]==c)^(s[i]==c))) j++;
      if (s[i]!=c) tmp = max(tmp, j-i);
      i = j;
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}