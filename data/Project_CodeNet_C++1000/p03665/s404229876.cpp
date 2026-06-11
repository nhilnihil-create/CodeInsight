#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Pow(ll a, ll n) {
  if (n == 1) return a;
  if (n % 2 == 1) return (a * Pow(a, n-1));
  ll t = Pow(a, n/2);
  return (t*t);
}

int main() {
  int N, P;
  cin >> N >> P;
  bool odd = false;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 1) {
      odd = true;
      break;
    }
  }
  if (!odd) {
    if (P % 2 == 0) cout << Pow(2, N);
    else cout << 0 << endl;
  }
  else cout << Pow(2, N-1);
}
