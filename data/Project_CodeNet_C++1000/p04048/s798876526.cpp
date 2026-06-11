#ifdef ConanYu
#include "local.hpp"
#else
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

void Main() {
  ll n, x; cin >> n >> x;
  ll g = __gcd(n, x);
  n /= g, x /= g;
  cout << ((n - 1) * 3ll * g) << "\n";
}
