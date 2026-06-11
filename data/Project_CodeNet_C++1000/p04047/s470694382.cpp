#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<int> L(N*2);
  rep(i,0,N*2) {cin >>L[i];}
  sort(L.begin(),L.end());
  int ans=0;
  for (int i=1;i<N*2;i+=2) {
    ans+=min(L[i],L[i-1]);
  }
  cout <<ans <<endl;
  return 0;
}
