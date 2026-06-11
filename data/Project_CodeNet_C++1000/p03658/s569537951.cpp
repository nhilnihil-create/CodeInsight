#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,K; cin >>N >>K;
  vector<int> l(N);
  rep(i,0,N) cin >>l[i];
  sort(l.rbegin(),l.rend());
  int ans=0;
  rep(i,0,K) ans+=l[i];
  cout <<ans <<endl;
  return 0;
}
