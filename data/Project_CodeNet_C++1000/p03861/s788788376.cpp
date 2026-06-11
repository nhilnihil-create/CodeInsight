#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  ll a, b, x; cin >> a >> b >> x;
  ll n1 = a / x;
  ll n2 = b / x;
  cout << n2 - n1 + (a % x == 0) << endl;
}
