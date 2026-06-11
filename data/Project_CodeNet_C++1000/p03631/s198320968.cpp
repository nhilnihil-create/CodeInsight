#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  string s, ans;
  cin >> s;
  if(s[0]==s[2]) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}