#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  int s,t;
  s=a-x;
  t=b-x;
  if(s<0)s=-s;
  if(t<0)t=-t;
  if(s>t)cout<<"B";
  else cout<<"A";
  
}
