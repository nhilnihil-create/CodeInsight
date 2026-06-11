#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s; cin >>s;
  int n = s.size();
  string ans = "";
  rep(i,n){
    if(s[i]=='0') ans += '0';
    else if(s[i]=='1') ans += '1';
    else if(s[i]=='B' && ans!="") {
      int x = ans.size();
      ans.erase(x-1,1);
    }
  }
  cout << ans << endl;
  return 0; 
}