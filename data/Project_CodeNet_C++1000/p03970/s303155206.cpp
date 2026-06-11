#include <bits/stdc++.h> 
using namespace std;
signed main(){
  int a=0;
  char s[16];
  string v="CODEFESTIVAL2016";
  for(int i=0;i<16;i++){
    cin>>s[i];
    if(s[i] != v[i])
      a++;
    }
  cout<<a<<endl;
  return(0);
}
