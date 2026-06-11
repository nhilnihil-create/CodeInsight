#include<bits/stdc++.h>
using namespace std;
long long i[11111111];
long long u[11111111];
long long o[11111111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a,b,c,d=0,e=1,f=0;
  string s;
  cin >>a>>i[0];
  u[0]=i[0];
  for(int n=1;n<a;n++) cin >>u[n],i[n]+=i[n-1]+u[n];
  o[a-1]=u[a-1];
  for(int n=a-2;n>=0;n--){
    o[n]=o[n+1]+u[n];
  }
  d=o[1]-i[0];
  if(d<0) d=-d;
  for(int n=1;n<a-1;n++){
    e=o[n+1]-i[n];
    if(e<0) e=-e;
    if(d>e) d=e;
  }
  cout <<d<<'\n';
  return (0);
}
