#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  
  int cnt1 = 0, cnt2 = 0;
  rep(i,n-1) if(s[i] == 'W' && s[i+1] == 'B') cnt1++;
  rep(i,n-1) if(s[i] == 'B' && s[i+1] == 'W') cnt2++;
  
  int ans = cnt1 + cnt2;
  
  cout << ans << endl;
  
  return 0;
}