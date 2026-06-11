#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const int Nmax=2e5+1;
const int Nd=61;
const int INF=1e5;


int main(){
  ll n,k; cin>>n>>k;
  ll ans=1;

  rep(i,n){
    if(i==0){
      ans=k;
    }else{
      ans*=(k-1);
    }
  }
  cout<<ans<<endl;

}
