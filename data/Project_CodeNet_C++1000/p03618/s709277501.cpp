#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  vector<long long> c(26);
  for (char d : s) {
    ++c[d - 'a'];
  }
  long long ans = (long long) s.size() * (s.size() - 1) / 2 + 1;
  for (int i = 0; i < 26; ++i) {
    ans -= c[i] * (c[i] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
