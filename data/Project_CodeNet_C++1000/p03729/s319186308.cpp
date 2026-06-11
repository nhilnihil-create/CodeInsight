#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,y,z;
  cin>>x>>y>>z;
  int l=x.length(),m=y.length();
  if(x.at(l-1)==y.at(0)&&y.at(m-1)==z.at(0)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}