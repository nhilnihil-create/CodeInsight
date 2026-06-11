#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;
  int ans = 2*N;
  for (int i=N; i>=1; i--) {
    string s_sub = s.substr(N-i, i), t_sub = t.substr(0, i);
    if (s_sub==t_sub) {
      ans -= i;
      break;
    }
  }
  cout << ans << endl;
}