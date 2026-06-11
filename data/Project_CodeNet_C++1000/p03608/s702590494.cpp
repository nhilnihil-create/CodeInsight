#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()
 
int main(){
  ll N,M,R,ans=1000000000;
  cin >> N >> M >> R;
  vector<ll> r(R);
  rep(i,R){
    cin >> r.at(i);
    r.at(i)--;
  }
  sort(all(r));
  vector<vector<ll>> d(N,vector<ll>(N,100000000));
  rep(i,N) d.at(i).at(i)=0;
  rep(i,M){
    ll a,b,c;
    cin >> a >> b >> c;
    d.at(a-1).at(b-1)=c;
    d.at(b-1).at(a-1)=c;
  }
  rep(k,N)rep(i,N)rep(j,N){
    d.at(i).at(j)=min(d.at(i).at(j),d.at(i).at(k)+d.at(k).at(j));
  }
  do{
    ll t=0;
    rep(i,R-1){
      t+=d.at(r.at(i)).at(r.at(i+1));
    }
    ans=min(ans,t);
  } while (next_permutation(all(r)));
  cout << ans << endl;
    
       
    
  
 
}