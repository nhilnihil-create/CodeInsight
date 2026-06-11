#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  ll m,x,y,z,w,b,j;
  cin>>m>>x>>y;
  for(j=1;j<m;j++){
    cin>>z>>w;
    b=max((x+z-1)/z,(y+w-1)/w);
    x=z*b;
    y=w*b;
  }
  cout<<x+y<<endl;
}