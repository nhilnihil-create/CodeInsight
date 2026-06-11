#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  vector<int> a(N);
  rep(i,0,N) cin >>a[i];
  int ans=0;
  rep(i,0,N) {
    if (a[a[i]-1]==i+1) ans+=1;
  }
  cout <<ans/2 <<endl;
  return 0;
}
