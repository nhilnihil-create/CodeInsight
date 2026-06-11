#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,K,X,Y; cin >>N >>K >>X >>Y;

  int ans=0;

  if (K<N) {
    rep_eq(i,1,K) {ans+=X;}
    rep_eq(i,1,N-K) {ans+=Y;}
  } else if (N<=K) {
    rep_eq(i,1,N) {ans+=X;}
  }

  cout <<ans <<endl;
  return 0;
}
