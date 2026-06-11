#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
using P=pair<int,int>;

int main(){
  int a,b;
  cin>>a>>b;
  a=(a+11)%13;
  b=(b+11)%13;
  if(a==b) cout<<"Draw"<<endl;
  else if(a>b) cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
}