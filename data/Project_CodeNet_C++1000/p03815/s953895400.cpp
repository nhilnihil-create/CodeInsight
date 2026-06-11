#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll x;cin>>x;
  ll cnt = x / 11;
  int rest = x % 11;
  cnt *= 2;
  if (rest>6) cnt += 2;
  else if (rest>0) cnt += 1;
  cout << cnt;
}
