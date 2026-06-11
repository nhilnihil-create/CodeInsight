#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  ll a,b,x; cin>>a>>b>>x;
  ll l,r;
  r=b/x+1;
  l=(a-1)/x+1;
  if(a==0){l=0;}
  cout<<r-l;
}

