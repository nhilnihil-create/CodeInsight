#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int n, k;
  cin >> n >> k;
  ll ans;
  ans = k * pow((k-1),n-1);
  cout << ans << endl;
}