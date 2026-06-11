#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  string s; cin >> s; int n = s.size();
  V<string> dp(26); for (int i = 0; i < 26; i++) dp[i] = 'a' + i;
  for (int i = n - 1; i >= -1; i--) {
    string t = *min_element(dp.begin(), dp.end(), [](string a, string b) { return a.size() < b.size(); });
    int j = i >= 0 ? s[i] - 'a' : 0;
    dp[j] = i >= 0 ? s[i] + t : t;
  }
  cout << dp[0] << '\n';
}