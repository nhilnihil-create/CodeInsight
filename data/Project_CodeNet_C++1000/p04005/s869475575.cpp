#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  if (A%2==0||B%2==0||C%2==0) cout << 0 << endl;
  else {
    ll num = max(A, max(B, C)), ans;
    if (num==A) ans = B*C;
    else if (num==B) ans = C*A;
    else ans = A*B;
    cout << ans << endl;
  }
}