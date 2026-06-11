#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = s.size()/2; 
  for (int i=0; i<s.size(); i++){
    ans -= (s[i]=='p') ? 1 : 0;
  }
  cout << ans << endl;
}