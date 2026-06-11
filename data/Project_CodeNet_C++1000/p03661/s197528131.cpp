#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  ll maxi = LLONG_MAX;
  ll cur = 0;
  rep(i,n-1) {
    cur += a[i];
    maxi = min(maxi,llabs(cur-(sum-cur)));
  }
  cout << maxi << endl;
  return 0;
}