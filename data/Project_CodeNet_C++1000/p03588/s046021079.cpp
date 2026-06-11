#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<pair<int,int>> pr(n);
  rep(i,n){
    int a,b;cin>>a>>b;
    pr[i]=make_pair(a,b);
  }
  sort(all(pr));
  reverse(all(pr));
  ll ans=pr[n-1].first+pr[0].second;
  rep(i,n-1){
    ans+=pr[i].first-pr[i+1].first;
  }
  cout<<ans<<endl;
}