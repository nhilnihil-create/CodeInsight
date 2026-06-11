#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

int group(ll x) {
  if (x == 2) {
    return 0;
  } else if (x==4||x==6||x==9||x==11) {
    return 1;
  } else {
    return 2;
  }
}

void solve(ll x, ll y) {
  bool pred = group(x) == group(y);
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll x;
  cin >> x;
  ll y;
  cin >> y;
  solve(x, y);
  return 0;
}
