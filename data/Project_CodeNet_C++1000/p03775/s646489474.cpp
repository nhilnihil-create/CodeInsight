#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll digit(ll a) {
  ll ans = 1;
  while (a >= 10) {
    a /= 10;
    ans++;
  }
  return ans;
}
int main() {
  ll N;
  cin >> N;
  ll ans;
  ll rN = sqrt(N);
  ll res = 0;
  ll anotherres = 0;
  for(ll i = rN; i >= 1; i--) {
    if (N % i == 0) {
      res = i; anotherres = N / i;
      break;
    }
  }
  ans = max(digit(res),digit(anotherres));
  cout << ans << endl;
  return 0;
}