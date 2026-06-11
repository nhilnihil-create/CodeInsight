#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 2100000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = true; //debug

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string x;
  cin >> x;
  int n = x.size();

  vector<char> stk;
  for (int i = 0; i < n; i++) {
    if (stk.size() == 0) {
      stk.push_back(x[i]);
    }
    else {
      if (x[i] == 'S') {
        stk.push_back(x[i]);
      }
      else {
        if (stk.back() == 'S') {
          stk.pop_back();
        }
        else {
          stk.push_back(x[i]);
        }
      }
    }
  }

  cout << stk.size() << endl;
}
