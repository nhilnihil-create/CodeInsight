#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,p="CODEFESTIVAL2016";
  cin>>s;long long i,m=0;
  for(i=0;i<16;i++){
      if(p[i]!=s[i])
      m++;
  }
cout<<m;
  return 0;
  
}