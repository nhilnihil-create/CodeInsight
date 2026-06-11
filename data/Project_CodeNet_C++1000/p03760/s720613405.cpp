#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,y;
  cin>>x>>y;
  int l=x.length(),m=y.length(),j;
  for(j=0;j<m;j++) cout<<x.at(j)<<y.at(j);
  if(l>m) cout<<x.at(m);
  cout<<endl;
}