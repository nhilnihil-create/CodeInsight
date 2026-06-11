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
  ll n,m;
  cin >> n >> m;
  vector<bool> prob(n,false);
  vector<ll> num(n,1);
  
  prob.at(0) = true;

  rep(i,m) {
    ll x,y;
    cin >> x >> y;
    x--;
    y--;

    num.at(x)--;
    num.at(y)++;

    if(prob.at(x)) {
      prob.at(y) = true;
    }

    if(num.at(x) == 0) {
      prob.at(x) = false;
    }

  }

  ll ans = 0;

  rep(i,n) {
    if(prob.at(i)) ans++;
  }

  cout << ans << endl;
}
