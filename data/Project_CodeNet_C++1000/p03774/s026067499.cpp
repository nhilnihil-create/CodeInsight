#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  int N,M; cin >>N >>M;
  vector<int> a(N);
  vector<int> b(N);
  rep(i,0,N) cin >>a[i] >>b[i];
  vector<int> c(M);
  vector<int> d(M);
  rep(i,0,M) cin >>c[i] >>d[i];

  vector<int> ans(N);
  rep(i,0,N) {
    int temp=INT_MAX;
    rep(j,0,M) {
      int check=abs(a[i]-c[j])+abs(b[i]-d[j]);
      if (check<temp) {ans[i]=j+1; temp=check;}
    }
  }
  rep(i,0,N) cout <<ans[i] <<endl;
  return 0;
}
