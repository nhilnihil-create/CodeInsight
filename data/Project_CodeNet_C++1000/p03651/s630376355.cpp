#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  ll n,k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  ll gcd = v[0];
  rep(i,n-1)gcd = __gcd(gcd,v[i+1]);
  if(*max_element(ALL(v)) < k){
    printf("IMPOSSIBLE\n");
  }else{
    if(k%gcd == 0){
      printf("POSSIBLE\n");
    }else{
      printf("IMPOSSIBLE\n");
    }
  }

  
  




  return 0;
}