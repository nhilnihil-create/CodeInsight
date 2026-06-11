#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  string t = "CODEFESTIVAL2016";
  int ans = 0;
  for(int i = 0; i < 16; i++){
    if(s[i] != t[i]) ans++;
  }
  cout << ans << endl;  
  return 0;
}