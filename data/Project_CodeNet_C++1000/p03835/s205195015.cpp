#include<iostream>
using namespace std;
int main(){
  int k,s; cin>>k>>s;
  int x,y,z;
  int i,j;
  int ans=0;
  for(i=0;i<=k;i++){
    x=i;
    for(j=0;j<=k;j++){
      y=j;
      z=s-x-y;
      if(0<=z && z<=k)ans+=1;
    }
  }
  cout<<ans<<endl;
}
