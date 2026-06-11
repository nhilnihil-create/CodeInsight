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
  string c;
  rep(i,h){
    cin >> c;
    rep(j,2){
      cout << c << endl;
    }
  }
  return 0;
}