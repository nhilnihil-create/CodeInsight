#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  map<char, int> cnt;
  for (int i = 0; i < s.size(); i++) cnt[(char)s[i]]++;

  if ((((cnt['N'] == 0) && (cnt['S'] != 0)) || ((cnt['N'] != 0) && (cnt['S'] == 0))) || (((cnt['E'] == 0) && (cnt['W'] != 0)) || ((cnt['E'] != 0) && (cnt['W'] == 0)))) cout << "No" << endl;
  else cout << "Yes" << endl;
}
