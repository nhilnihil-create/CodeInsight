#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long

signed main() {
  string s;
  cin >>s;
  for(int i=s.length()-2;i>=2;i-=2) {
    string ss = s.substr(0,i/2);
    string sss = s.substr(i/2,i/2);
    //cout << i<<" "<<ss <<" "<<sss << endl;
    if(ss==sss) {
      cout << ss.length()*2 << endl;
      return 0;
    }
  }
  
  return 0;
}