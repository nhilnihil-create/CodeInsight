#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 2; i <= n; ++i)
using ll = long long;
using P = pair<int, int>;

ll power;

int main() {
  int n;
  cin >> n;
  power = 1;
  rep (i, n) {
    power *= i;
    power %= 1000000007;
  }
  cout << power << endl;
  return 0;
}
