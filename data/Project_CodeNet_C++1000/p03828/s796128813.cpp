#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;

map<ll,ll>g;
set<ll> h;

void prime_factorize(long long N) {
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        g[a]+=ex;
        h.insert(a);
    }

    // 最後に残った数について
    if (N != 1){g[N]++;h.insert(N);};
    return;
}

int main(){
  ll n;
  cin >>n;

  ll ans=1;
  for(int i=1;i<=n;i++){
    prime_factorize(i);
  }
  while(!h.empty()){
    auto d=h.begin();
    ans*=g[*d]+1;
    ans%=mod;
    h.erase(d);
  }
  cout << ans << endl;
}