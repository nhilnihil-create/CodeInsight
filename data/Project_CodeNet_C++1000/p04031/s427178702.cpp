#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  vector<int> a(N);
  rep(i,0,N) {cin >>a[i];}

  sort(a.begin(),a.end());

  int ans=INT_MAX;
  rep_eq(i,a.front(),a.back()) {
    int sum=0;
    rep(j,0,N) {
      int x=pow(a[j]-i,2);
      sum+=x;
    }
    ans=min(ans,sum);
  }

  cout <<ans <<endl;
  return 0;
}
