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
  int k;
  cin >> k;
  rep(i, s.size()-1){
    char now = s.at(i);
    if(now == 'a') continue;
    // cerr  << 'z' - now << endl;
    if('z' - now + 1 <= k){
      s.at(i) = 'a';
      k -= 'z' - now + 1;
    }
    if(k == 0) break;
  }
  int c = s.back() - 'a';
  c += k;
  c %= 26;
  s.back() = 'a' + c;
  cout << s << endl;
  return 0;
}