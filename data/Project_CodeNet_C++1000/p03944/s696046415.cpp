#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int w,h,n,x,y,a; 
  cin>>w>>h>>n;
  int v1=0,v2=w,v3=0,v4=h;
  rep(i,n){
    cin>>x>>y>>a;
    if(a==1){v1=max(v1,x);}
    if(a==2){v2=min(v2,x);}
    if(a==3){v3=max(v3,y);}
    if(a==4){v4=min(v4,y);}
  }
  int p=max(0,v2-v1);
  int q=max(0,v4-v3);
  cout<<p*q;
}