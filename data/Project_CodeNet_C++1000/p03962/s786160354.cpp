#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int a,b,c;
  cin>>a>>b>>c;
  if(a!=b && b!=c && a!= c) cout<<3;
  else if(a!=b || b!=c ||a!=c) cout<<2;
  else cout<<1;
  cout<<endl;
  return 0;
}