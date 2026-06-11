#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, int> PL;
constexpr int mod = 1e9 + 7;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      vector<int> res;
      res.emplace_back(i);
      res.emplace_back(j);
      for (int k = 0; k < n; k++) {
        if (s[k] == 'o') res.emplace_back(res[k] ^ res[k + 1]);
        else res.emplace_back(res[k] ^ res[k + 1] ^ 1);
      }
      if (res[n] == i && res[n + 1] == j) {
        for (int l = 1; l <= n; l++) cout << (res[l] ? 'W' : 'S');
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
} 