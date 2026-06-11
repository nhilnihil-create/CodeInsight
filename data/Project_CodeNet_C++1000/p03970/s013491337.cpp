#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  string c = "CODEFESTIVAL2016";
  string s; cin >> s;
  int ans = 0;
  REP(i, 16) ans += s[i]!=c[i];
  cout << ans << endl;
}