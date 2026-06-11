#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int ll

main(){
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> p(n);
  rep(i,n){
    int a, b;
    cin >> a >> b;
    p[i]=make_pair(a,b);
  }
  sort(p.begin(),p.end());
  int ans;
  ll tmp=0;
  rep(i,n){
    tmp += p[i].second;
    if(tmp >= k){
      ans=p[i].first;
      break;
    }
  }
  cout<<ans<<endl;
}