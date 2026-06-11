#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n,p;
  cin >> n >> p;

  ll ans = 1;
  rep(i,n) {
    ans *= 2;
  }
  bool flag = true;
  rep(i,n) {
    int a;
    cin >> a;
    if(a % 2 == 1) flag = false;
  }

  if(flag) {
    if(p == 0){
      cout << ans << endl;
      return 0;
    }
    else {
      cout << 0 << endl;
      return 0;
    }
    
  }
  else {
    cout << ans / 2 << endl;
  }
  
}
