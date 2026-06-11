#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y,m=1000000007;cin>>x>>y;
  if(x<y)m=min(m,y-x);
  else m=min(m,2-y+x);
  if(-x<y)m=min(m,1+y+x);
  else m=min(m,1-y-x);
  cout<<m<<endl;
}