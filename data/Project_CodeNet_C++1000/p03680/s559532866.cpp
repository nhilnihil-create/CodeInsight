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
  int n;
  cin >> n;
  vector<int> nx(n);
  int ans = 0;
  rep(i, n){
    int in;
    cin >> in;
    nx.at(i) = in - 1;
  }
  int now = 0;
  while(now != 1){
    auto &p = nx.at(now);
    now = p;
    if(now == -1){
      ans = -1;
      break;
    }else{
      p = -1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}