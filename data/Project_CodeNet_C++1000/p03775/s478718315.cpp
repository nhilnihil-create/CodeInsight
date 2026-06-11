#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  ll n,a; cin>>n;
  ll m=pow(n,0.5);
  for(ll i=m; i>=1; i--){
    if(n%i==0){
      a=n/i;break;
    }
  }
  int k=0;
  while(a!=0){a/=10;k++;}
  cout<<k;
}


