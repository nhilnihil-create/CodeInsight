#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,T; cin >>N >>T;
  vector<int> t(N);
  rep(i,0,N) cin >>t[i];
  ll ans=0;
  rep(i,0,N-1) ans+=min(t[i+1]-t[i],T);
  cout <<ans+T <<endl;
  return 0;
}
