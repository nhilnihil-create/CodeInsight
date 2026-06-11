#include <bits/stdc++.h>

using namespace std;

int main(){

  string s;
  cin>>s;
  
  int cnt_a=200010;
  int cnt_z=0;


  for(int i=0; i<s.size(); i++){
    
    if(s[i]=='A') cnt_a=min(cnt_a, i);
    else if(s[i]=='Z') cnt_z=max(cnt_z, i);
  }

  cout<<cnt_z - cnt_a +1 <<endl;
}
