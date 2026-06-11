#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll Q, H, S, D;
  cin >> Q >> H >> S >> D;
  ll N; cin >> N;
  Q *= 4; H *= 2;
  ll x = 0;
  if(D <= 2 * Q && D <= 2 * H && D <= 2 * S) {
    x += ((N / 2) * D);
    if(N % 2 == 1) {
      x += min(Q, min(H, S));
    }
  } else {
    x += min(Q, min(H, S)) * N;
  }
  cout << x << endl;
}