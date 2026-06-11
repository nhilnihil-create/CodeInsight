#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

//nCr
ll nCr(ll n,ll r){
    ll x=1;
    for(ll i=n; i>n-r; i--) x*=i;
    for(ll i=1; i<=r; i++) x/=i;
    return x;
}

int main() {
  ll n,p;
  cin>>n>>p;
  ll a;
  ll even=0, odd=0;
  rep(i,n){
    cin>>a;
    if(a%2==0){even++;}
    else{odd++;}
  }
  ll c=pow(2,even);
  ll b=0;
  if(odd==0&&p==1){b=0;}
  else if(p==0){
    for(ll i=0;i<=odd/2;i++){
      ll m= min(2*i, odd-2*i);
      b+=nCr(odd,m);
    }
  }
  else if(p==1){
    for(ll i;i<=(odd-1)/2;i++){
      ll m= min(2*i+1, odd-2*i-1);
      b+=nCr(odd,m);
    }
  }
  
  cout<<c*b;
  
}
      