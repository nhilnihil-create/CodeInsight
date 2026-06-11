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
  int i, o, t;
  cin >> i >> o >> t;
  int j, l, s, z;
  cin >> j >> l >> s >> z;
  ll ans = 0;
  ans += o;
  vector<int> v = {i, j, l};
  int co = 0;
  bool f = false;
  for(int x : v){
    if(x % 2 == 1) co++;
    if(x == 0) f = true;
  }
  if(co >= 2 && f == false){
    if(co == 2){
      rep(m, 3){
        if(v.at(m) % 2 == 0){
          v.at(m)--;
        }
      }
    }
    ans += 3;
  }
  for(int x : v){
    ans += x/2*2;
  }
  cout << ans << endl;
  return 0;
}