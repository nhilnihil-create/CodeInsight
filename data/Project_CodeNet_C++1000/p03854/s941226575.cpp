#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<bool>dp((int)s.size()+1213,0);
  int n=s.size();
  dp[0]=1;
  for(int i=0;i<n;++i){
    if(dp[i]==0)continue;
    if(i+5<=n && s.substr(i,5)=="dream")dp[i+5]=1;
    if(i+7<=n && s.substr(i,7)=="dreamer")dp[i+7]=1;
    if(i+5<=n && s.substr(i,5)=="erase")dp[i+5]=1;
    if(i+6<=n && s.substr(i,6)=="eraser")dp[i+6]=1;
  }
  if(dp[n])cout << "YES" << endl;
  else cout << "NO" << endl;
}