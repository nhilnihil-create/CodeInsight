#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> ab(n);

  rep(i,n){
    ll anum,bnum;
    scanf("%lld %lld",&anum,&bnum);
    ab.at(i).first = anum;
    ab.at(i).second = bnum;
  }
  sort(ab.begin(),ab.end());
  
  ll cnt = 0;
  rep(i,n){
    cnt += ab.at(i).second;
    if( cnt >= k ){
      cout << ab.at(i).first << endl;
      return 0;
    }
  }
  return 0;
  
}
