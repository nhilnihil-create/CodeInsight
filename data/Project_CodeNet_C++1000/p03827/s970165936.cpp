#include <bits/stdc++.h>

using namespace std;

int main(){

  int x=0;
  int n;
  cin>>n;
  string s;
  cin>>s;
  int ans=0;

  for(int i=0; i<s.size(); i++){
  
    if(s[i]=='I') x+=1;
    else if(s[i]=='D') x-=1;
    
    ans=max(ans, x);

  }

  cout<<ans<<endl;
}
