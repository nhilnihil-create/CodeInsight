#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

const ll DIV = 1000000007;

int main() {
  ll n;
  cin >> n;
  ll x = 1;
  for (int i = 1; i <= n; i++) {
    x = i * x % DIV;
  }
  cout << x << endl;

  return 0;
}