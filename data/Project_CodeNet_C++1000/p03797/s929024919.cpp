#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main(){
  ll N,M; cin >>N >>M;
  ll ans=0;
  if (N*2<=M) {
    ans+=N;
    M-=N*2;
    ans+=M/4;
  } else {
    ll temp=M/2;
    N-=temp;
    if (0<N) ans+=temp;
  }
  cout <<ans <<endl;
}
