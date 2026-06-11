#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s1,s2;
  cin >> n >> s1 >> s2;

  long long ans;
  int i;
  bool ver;
  if(s1[0]==s2[0]){
    ans=3;
    i=1;
    ver = true;
  }
  else{
    ans=6;
    i=2;
    ver=false;
  }
  
  for (i=i; i < n; i++)
  {
    if(s1[i]==s2[i]){
      if(ver){
        ans*=2;
      }
      else{
        ver=true;
      }
    }
    else{
      if(ver){
        ans*=2;
        ver=false;
      }
      else{
        ans*=3;
      }
      i++;
    }
    ans%=1000000007;
  }
  cout << ans << endl;
}