#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int n; cin >>n;
  int b1=0,b2=0,b4=0;
  rep(i,0,n) {
    int a; cin >>a;
    if (!(a&3)) b4+=1;
    else if (!(a&1)) b2+=1;
    else b1+=1;
  }
  int ans=0;
  if (b2==n) ans=1;
  else if (b2==0 && b4-b1>=-1) ans=1;
  else if (b2>0 && b4-b1>=0) ans=1;
  if (ans==1) cout <<"Yes" <<endl;
  else cout <<"No" <<endl;
  return 0;
}
