#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int main(){
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  long long ans;
  bool c;
  if(s[0]==t[0]){
    ans=3;
    c=true;
  }
  else{
    ans=6;
    c=false;
  }
  for(int i=1;i<n;i++){
    if(s[i-1]==s[i]){
      continue;
    }
    if(s[i]==t[i]){
      if(c){
        ans*=2;
        ans%=mod;
      }
      else{
        ans%=mod;
        c=true;
      }
    }
    else{
      if(c){
        ans*=2;
        ans%=mod;
        c=false;
      }
      else{
        ans*=3;
        ans%=mod;
      }
    }
  }
  cout << ans << endl;
}