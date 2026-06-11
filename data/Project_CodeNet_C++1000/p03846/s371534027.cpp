#include<bits/stdc++.h>
using namespace std;
int main(){
  int l,x,j,z=1e9+7;
  int64_t y=1;
  cin>>l;
  vector<int> v(l);
  for(j=0;j<l;j++){
    cin>>x;
    v.at(x)++;
  }
  for(j=l-1;j>0;j-=2){
    if(v.at(j)!=2){
      y=0;
      break;
    }
  }
  if(j==0&&v.at(j)!=1) y=0;
  if(y==1) for(j=0;j<l/2;j++) y=y*2%z;
  cout<<y<<endl;
}