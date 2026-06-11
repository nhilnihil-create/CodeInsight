#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,j,y=0,z,w,t=0;
  cin>>m;
  vector<int> x(m);
  for(j=0;j<m;j++){
    cin>>x[j];
    y+=x[j];
  }
  z=abs(y);
  w=z/m;
  if(z%m*2>m) w++;
  if(y<0) w*=-1;
  for(j=0;j<m;j++) t+=(x[j]-w)*(x[j]-w);
  cout<<t<<endl;
}