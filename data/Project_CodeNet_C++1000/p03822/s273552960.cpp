#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

  ll N;
  vector<vector<ll>> A(100000,vector<ll>(0));
  vector<ll> dp(100000);
void dfs(ll n){
  if(A.at(n).size()==0){
    dp.at(n)=0;
    return;
  }
  ll a=0,k=A.at(n).size();
  vector<ll> x(k);
  rep(i,k){
    dfs(A.at(n).at(i));
    x.at(i)=dp.at(A.at(n).at(i));
  }
  sort(all(x));
  rep(i,k){
    a=max(a,x.at(i)+k-i);
  }
  dp.at(n)=a;
  return;
}
  
  
int main(){
  cin >> N;
  rep(i,N-1){
    ll a;
    cin >> a;
    A.at(a-1).push_back(i+1);
  }
  dfs(0);
  cout << dp.at(0) << endl;
  
}
