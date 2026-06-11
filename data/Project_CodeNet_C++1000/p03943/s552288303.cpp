#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  vector<int> v(3);
  rep(snip_i, 3) cin >> v.at(snip_i);
  sort(v.begin(), v.end());
  if(v.at(2) == v.at(1) + v.at(0)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}