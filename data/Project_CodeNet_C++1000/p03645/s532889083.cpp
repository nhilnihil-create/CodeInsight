#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ull i=0;i<(ull)n;++i)
const ull INF = 999999999999999;



int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> array(n);
  rep(i,m){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    --a;
    --b;
    array.at(a).push_back(b);
  }
  rep(i,array.at(0).size()){
    ll num = array.at(0).at(i);
   rep(j,array.at(num).size()){
     if( array.at(num).at(j) == n-1 ){
       cout << "POSSIBLE" << endl;
       return 0;
     }
   }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}