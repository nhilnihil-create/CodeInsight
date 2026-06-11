#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, c, k;
  cin >> n >> c >> k;
  int ans = 0;
  vector<int> tt(n);
  rep(snip_i, n) cin >> tt.at(snip_i);
  sort(tt.begin(), tt.end());
  deque<int> td;
  rep(i, n){
    int t = tt.at(i);
    if(td.size() > 0 &&  t - td.front() > k){
      ans++;
      td.clear();
    }
    td.push_back(t);
    if(td.size() == c){
      ans++;
      td.clear();
    }
    // cerr << ans << endl;
  }
  if(td.size() > 0)ans++;
  cout << ans << endl;
  return 0;
}