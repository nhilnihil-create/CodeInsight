#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int X,t; cin >>X >>t;
  int ans=X-t;
  if (ans<0) ans=0;
  cout <<ans <<endl;
  return 0;
}
