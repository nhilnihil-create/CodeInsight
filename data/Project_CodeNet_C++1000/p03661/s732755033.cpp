#include<bits/stdc++.h>
using namespace std;
#define int long long
int abs(int a,int b){
  int c=max(a,b)-min(a,b);
  return c;
}
signed  main(){
  int a,c=0,d=0,x=1;
  int q,w;
  int b[1000000];
  int z=10000000;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b[i];
    if(i==0) c=b[0];
    else d+=b[i];
  }
  z=abs(c,d);
  for(int i=1;i<a-1;i++){
    q=c,w=d;
    c+=b[i];
    d-=b[i];
z=min(abs(c,d),z);
    x++;
  }
  cout<<z<<"\n";
}
