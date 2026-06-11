#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int w, h;
  cin >> w >> h;
  vector<int> p(w);
  rep(i, w) cin >> p.at(i);
  vector<int> q(h);
  rep(i, h) cin >> q.at(i);
  sort(ALL(p)), sort(ALL(q));
  p.push_back(1e9), q.push_back(1e9);
  int ip = 0, iq = 0;
  ll ans = 0;
  while(ip != p.size()-1 || iq != q.size()-1){
    ll np = p.at(ip), nq = q.at(iq);
    // np *= h-iq+1; nq *= w-ip+1;
    if(np < nq){
      np *= h-iq+1;
      ans += np;
      ip++;
    }else{
      nq *= w-ip+1;
      ans += nq;
      iq++;
    }
  }
  cout << ans << endl;
  return 0;
}