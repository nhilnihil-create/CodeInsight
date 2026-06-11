#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int h, w;
  cin >> h >> w;
  string ans = "";
  rep(i,h) {
    rep(j,w) {
      string s;
      cin >> s;
      if(s == "snuke") {
        ans += 'A' + j; 
        if(i >= 9) ans += '1';
        ans += '0' + ((i+1) % 10);
      }
    }
  }
  cout << ans << endl;
  return 0;
}