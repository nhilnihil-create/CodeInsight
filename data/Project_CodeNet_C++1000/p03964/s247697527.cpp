#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
  int N; cin >>N;

  ll takahashi=1,aoki=1;
  rep(i,0,N) {
    int T,A; cin >>T >>A;
    ll n=max(ll((takahashi+T-1)/T),ll((aoki+A-1)/A));
    takahashi=n*T;
    aoki=n*A;
  }
  cout<<takahashi+aoki <<endl;
  return 0;
}
