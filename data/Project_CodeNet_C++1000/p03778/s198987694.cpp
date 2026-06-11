#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int w,a,b;
  cin>>w>>a>>b;
  int x=a;
  int y=b;
  a=min(a,y);
  b=max(b,x);
  if(a+w>b) cout<<"0"<<endl;
  else cout<<b-(a+w)<<endl;
}