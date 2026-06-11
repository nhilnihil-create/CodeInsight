#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
  int N,K;
  cin>>N>>K;
  vector<int>l(N);
  rep(i,N){
      cin>>l[i];
  }
  int ans=0;
  sort(l.rbegin(),l.rend());
  rep(i,K){
      ans+=l[i];
  }
  cout<<ans<<endl;
}
