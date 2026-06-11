#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
  string s; cin >> s;
  int len = s.size();
  ll ans=0;
  for (int tmp = 0; tmp < (1 << len-1); ++tmp) {
    ll ver = s[0] - '0';
    for(int i=0; i<len-1; ++i){
      if(tmp & (1 << i)){
        ans += ver;
        ver=0;
      }
      ver = ver * 10 + s[i + 1] - '0';
    }
    ans += ver;
  }  
  cout << ans << endl;
}