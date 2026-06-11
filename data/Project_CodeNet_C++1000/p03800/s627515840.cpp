#include <bits/stdc++.h>
using namespace std;
const char m = 'o';
const char b = 'x';
int main(){
  int n;
  string s;
  cin >> n >> s;
  string ans;
  string st[4];
  st[0] = "SS";
  st[1] = "SW";
  st[2] = "WS";
  st[3] = "WW";
  for(int j = 0;j < 4;j++){
    ans = st[j];
    for(int i = 0;i < n;i++){
      if(ans[i+1] == 'S'){
        if(s[(i+1)%n] == m) ans += ans[i];
      	else if(ans[i]== 'S')ans += "W";
      	else ans += "S";
   	  }else{
      	if(s[(i+1)%n] == b)ans += ans[i];
      	else if(ans[i]== 'S')ans += "W";
      	else ans += "S";
      }
  	}
    if(ans[n] == ans[0] && ans[n+1] == ans[1]){     
      cout << ans.substr(0,n) << endl;
      break;
    }
    else if(j == 3)cout << -1 << endl;
  }
}