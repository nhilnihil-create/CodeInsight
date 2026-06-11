#include <bits/stdc++.h>
#define ll long long
const int mo = 1e9+7;
using namespace std;
int gi(){
  char ch=getchar(); int x=0,q=0;
  while(ch<'0' || ch>'9') (ch=='-'?q=1:0),ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
ll ans,x,y,sx,sy;
int main(){
  int n=gi(),m=gi(),v;
  for (int i=1; i<=n; ++i){
    v=gi(); sx+=1ll*(i-1)*v-x;
    x+=v;
  }
  for (int i=1; i<=m; ++i){
    v=gi(); sy+=1ll*(i-1)*v-y;
    y+=v;
  }
  sx%=mo,sy%=mo;
  cout<<sx*sy%mo;
  return 0;
}
