#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  int r;
  if(x>y) swap(x,y);
  r=y%x;
  while(r>0){
    y=x;
    x=r;
    r=y%x;
  }
  return x;
}
int main(){
  int x,y,z,w;
  cin>>x>>y>>z;
  w=gcd(x,y);
  if(z%w==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}