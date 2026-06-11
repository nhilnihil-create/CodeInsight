#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll ans=1;
  sort(a.begin(),a.end());
  bool is=true;
  if(n%2==1){
    if(a.at(0)!=0){
      is=false;
    }
    ll p=2;
    for(ll i=1;i<n;i+=2){
      if(a.at(i)!=a.at(1+i) || a.at(i) != p){
        is=false;
      }
      p+=2;
    }
  }else{
    ll p=1;
    for(ll i=0;i<n;i+=2){
      if(a.at(i)!=a.at(i+1) || a.at(i)!=p){
        is=false;
      }
      p+=2;
    }
  }
  if(is){
    if(n%2==1){
      n--;
    }
    n=n/2;
    ll mod=1e9+7;
    for(ll j=0;j<n;j++){
      ans=ans*2;
      ans%=mod;
    }
  }else{
    ans=0;
  }
  cout << ans;
}