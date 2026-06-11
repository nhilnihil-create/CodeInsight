#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll K,S,ans=0;
  cin >> K >> S;
  rep(i,K+1){
    rep(j,K+1){
      if(S-i-j<=K&&S-i-j>=0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
  