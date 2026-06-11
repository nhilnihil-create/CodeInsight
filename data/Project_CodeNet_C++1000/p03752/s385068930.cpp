#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,K,ans=INF;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<15> s(tmp);
    if(s.count()!=K){
      continue;
    }
    ll m=0,n=0;
    rep(i,N){
      if(s.test(i)){
        if(m>=A.at(i)){
          n+=m-A.at(i)+1;
          m++;
        }
      }
      m=max(m,A.at(i));
    }
    ans=min(ans,n);
  }
  cout << ans << endl;
}