#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9 + 7;

int main(){
  ll n;
  cin>>n;
  ll count = 1%mod;
  for (ll i=2;i<=n;++i){
    count=count*i%mod;
  }
  cout<<count;
}