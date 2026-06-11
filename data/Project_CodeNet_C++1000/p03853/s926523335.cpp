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
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  rep(i,h) cin >> c[i];
  rep(i,h){
    cout << c[i] << endl;
    cout << c[i] << endl;
  }
  return 0;
}
