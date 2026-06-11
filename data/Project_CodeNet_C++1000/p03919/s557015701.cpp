#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    string s;
    cin >> s;
    if (s == "snuke") {
      cout << char('A'+j) << i+1 << endl;
    }
  }

}