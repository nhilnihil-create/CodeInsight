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
  int a, b, c;
  cin >> a >> b >> c;
  int now = a % b;
  vector<bool> chk(b, false);
  while(1){
    if(chk.at(now) == false){
      chk.at(now) = true;
      now = (now + a) % b;
    }else break;
  }
  if(chk.at(c) == true) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}