#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

vector<ll> Prime(1000000,0);
void sosu(ll n){
  Prime.at(0)=2;
  ll t=1;
  for(ll i=3;i<n;i++){
    rep(j,t){
      if(i%Prime.at(j)==0){
        break;
      }
      if(j==t-1){
        Prime.at(t)=i;
        t++;
      }
    }
  }
}

int main(){
  string S;
  ll ans=0;
  cin >> S;
  rep(i,S.size()-1){
    if(S.at(i+1)!=S.at(i)){
      ans++;
    }
  }
  cout << ans << endl;
}