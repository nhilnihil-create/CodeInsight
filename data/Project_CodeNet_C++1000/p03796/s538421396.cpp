#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

ll mod=1e9+7;

int main(){
  int N; cin >>N;
  ll ans=1;
  rep_eq(i,1,N) {
    ans=(ans*i)%mod;
  }
  cout <<ans <<endl;
}
