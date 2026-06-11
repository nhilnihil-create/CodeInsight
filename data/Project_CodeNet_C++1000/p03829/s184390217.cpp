#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  ll N,A,B; cin>>N>>A>>B;
  vector<ll> X(N); rep(i,N)cin>>X.at(i);
  vector<ll> dp(N,INF);
  dp.at(0)=0;
  rep1(i,N){
    dp.at(i)=dp.at(i-1)+B;
    dp.at(i)=min(dp.at(i),dp.at(i-1)+((X.at(i)-X.at(i-1))*A));
  }
  cout<<dp.at(N-1)<<endl;
}