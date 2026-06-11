#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll euclidean_gcd(ll a, ll b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}


int main() {
  int a, b, c, d;
  cin >> a >> b >> c >>d;
  int s = max(a,c);
  int t = min(b,d);
  cout << max(0,t-s) << endl;
  return 0;
}