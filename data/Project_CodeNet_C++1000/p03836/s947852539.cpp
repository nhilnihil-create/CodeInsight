#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main() {
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  rep(i,0,tx-sx) cout<<'R';
  rep(i,0,ty-sy) cout<<'U';
  rep(i,0,tx-sx) cout<<'L';
  rep(i,0,ty-sy) cout<<'D';
  cout<<'D';
  rep(i,0,tx-sx+1) cout<<'R';
  rep(i,0,ty-sy+1) cout<<'U';
  cout<<'L';
  cout<<'U';
  rep(i,0,tx-sx+1) cout<<'L';
  rep(i,0,ty-sy+1) cout<<'D';
  cout<<'R';
  cout<<endl;
}
