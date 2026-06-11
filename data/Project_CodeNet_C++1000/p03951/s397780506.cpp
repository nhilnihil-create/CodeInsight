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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int mx = 0;
  rep(i, s.size()){
    bool f = false;
    rep(j, s.size()-i){
      if(s.at(i+j) != t.at(j)){
        f = true;
        break;
      }
    }
    if(f == false){
      mx = s.size() - i;
      break;
    }
  }
  cout << s.size()+t.size()-mx << endl;
  return 0;
}