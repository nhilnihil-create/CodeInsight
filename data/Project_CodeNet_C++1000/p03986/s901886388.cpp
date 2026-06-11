#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string X;
  cin >> X;
  stack<char> L{}, R{};
  REP(i, X.size()) { R.push(X[X.size() - 1-i]); }
  while (!R.empty()) {
    L.push(R.top());
    R.pop();
    while (!R.empty() && !L.empty()) {
      if (L.top() == 'S' && R.top() == 'T') {
        L.pop(), R.pop();
      } else {
        break;
      }
    }
  }
  ll ans = 0;
  while (!L.empty()) {
    ans++;
    L.pop();
  }
  cout << ans << endl;
}