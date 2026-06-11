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
  string s;
  cin >> s;
  vector<bool> ans(n);
  rep(i, 2){
    rep(j, 2){
      ans.at(0) = i, ans.at(1) = j;
      rep(k, n){
        int k1 = k, k2 = (k+1) % n, k3 = (k+2) % n;
        bool m = (s.at(k2) == 'o');
        if(ans.at(k2) == false) m ^= 1;
        if(m == true) ans.at(k3) = ans.at(k1);
        else ans.at(k3) = !ans.at(k1);
      }
      if(ans.at(0) == i && ans.at(1) == j){
        rep(i, n){
          char o;
          if(ans.at(i) == true) o = 'S';
          else o = 'W';
          cout << o;
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}