#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main() {
  string s;
  cin >> s;
  string x = "CODEFESTIVAL2016";
  int ans = 0;
  rep(i,16) if (s[i] != x[i]) ans++;
  cout << ans << endl;
  return 0;
}
