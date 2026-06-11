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
  int n, m;
  cin >> n >> m;
  vector<bool> ans(n, false);
  vector<int> co(n, 1);
  ans.at(0) = true;
  rep(i, m){
    int x, y;
    cin >> x >> y;
    x--; y--;
    co.at(y)++;
    if(ans.at(y) == false)ans.at(y) = ans.at(x);
    co.at(x)--;
    if(co.at(x) == 0) ans.at(x) = false;
  }
  int out = 0;
  rep(i, n) if(ans.at(i) == true) out++;
  cout << out << endl;
  return 0;
}