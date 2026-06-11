#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;
  ll w=tx-sx,h=ty-sy;
  rep(i,w) cout<<"R";
  rep(i,h) cout<<"U";
  rep(i,w) cout<<"L";
  rep(i,h) cout<<"D";
  cout<<"D";
  rep(i,w+1) cout<<"R";
  rep(i,h+1) cout<<"U";
  cout<<"L";
  cout<<"U";
  rep(i,w+1) cout<<"L";
  rep(i,h+1) cout<<"D";
  cout<<"R";
  cout<<endl;
  return 0;
}
