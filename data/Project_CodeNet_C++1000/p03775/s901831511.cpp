#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;

int f(int a, int b) {
  return max(to_string(a).length(), to_string(b).length());
}

int main() {
  ll n;
  cin >> n;

  int minv = 1000000000;

  rep2(i, sqrt(n)) {
    if (n % i == 0) minv = min(minv, f(i, n / i));
  }

  cout << minv << endl;

  return 0;
}
