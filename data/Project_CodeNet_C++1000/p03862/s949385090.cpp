#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t y=0;
  int m,x,z,j;
  cin>>m>>x;
  vector<int> b(m);
  for(j=0;j<m;j++) cin>>b.at(j);
  for(j=1;j<m;j++){
    z=b.at(j-1)+b.at(j)-x;
    if(z>0){
      y+=z;
      if(b.at(j)>=z) b.at(j)-=z;
      else if(b.at(j)<z){
        b.at(j)=0;
        b.at(j-1)=x;
      }
    }
  }
  cout<<y<<endl;
}