#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int N,x; cin >>N >>x;
  vector<int> a(N);
  vector<int> check(N);
  rep(i,0,N) {
    cin >>a[i];
    check[i]=a[i];
  }
  rep(i,0,N) {
    if (x<check[i]) check[i]=x;
  }
  rep(i,0,N-1) {
    if (x<check[i]+check[i+1]) check[i+1]=x-check[i];
  }
  ll ans=0;
  rep(i,0,N) {
    ans+=a[i]-check[i];
  }
  cout <<ans <<endl;
  return 0;
}
