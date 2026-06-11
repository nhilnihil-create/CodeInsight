#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  ll P = 0;
  ll m = min (D, S * 2);
  m = min(m, H * 4);
  m = min(m, Q * 8);
  
  if (m == D) {
    ll PD = N / 2 * D;
    ll m2 = min(S, H * 2);
    m2 = min(m2, Q * 4);
    ll PS = (N % 2) * m2;
    P = PD + PS;
  }
  else P = N * m / 2;
  
  cout << P << endl;
}