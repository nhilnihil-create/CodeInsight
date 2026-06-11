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
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size()){
    mp[s.at(i)]++;
  }
  vector<int> p(26, 1);
  ll ans = 1;
  rep(i, s.size()){
    ll add = (s.size() - 1 - i);
    int mc = mp[s.at(i)] - p.at(s.at(i)-'a');
    ans += add - mc;
    p.at(s.at(i) - 'a')++;
  }
  cout << ans << endl;
  return 0;
}