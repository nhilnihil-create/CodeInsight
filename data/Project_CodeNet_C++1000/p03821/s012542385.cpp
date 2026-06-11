#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);

  rep(i,n) {
    cin >> a.at(i) >> b.at(i);
  }

  ll count = 0;

  //cout << 2 << endl;
  for(int i = n - 1; i >= 0; i--) {
    //cout << i << endl;
    a.at(i) += count;
    ll remainder = b.at(i) - ( a.at(i) % b.at(i) );
    if(remainder == b.at(i) ) remainder = 0;
    count += remainder;
  }

  cout << count << endl;
}
