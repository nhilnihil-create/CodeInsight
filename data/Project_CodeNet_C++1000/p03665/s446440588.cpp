#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

long long pow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int main() {
  int n,p,o = 0,d = 0;
  ll ans = 1;
  cin >> n >> p;
  rep(i,n){
    int a;
    cin >> a;
    if(a%2 == 0) d++;
    else o++;
  }
  if(d != 0) ans *= pow(2,d);
  if(p == 0){
    if(o > 1) ans *= pow(2,o-1);
  }
  else{
    if(o == 0) ans *= 0;
    else ans *= pow(2,o-1);
  }
  cout << ans << endl;
}