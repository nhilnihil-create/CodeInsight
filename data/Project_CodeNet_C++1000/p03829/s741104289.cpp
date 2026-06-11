#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll cost = 0;
  VI X(N);
  ll xbeg;
  cin >> xbeg;
  rep(i, N - 1) {
    ll xtemp;
    cin >> xtemp;
    cost += min((xtemp - xbeg) * A, B);
    xbeg = xtemp;
  }

  cout << cost << endl;
  return 0;
}
