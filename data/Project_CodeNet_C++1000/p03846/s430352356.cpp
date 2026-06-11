#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll MOD = 1000000007;

ll absdif(ll x, ll y){
  ll ret;

  if(x - y >= 0){
    ret = x - y;
  } else{
    ret = y - x;
  }

  return ret;
}

int main(){
  ll N;
  cin >> N;

  ll A;
  map<ll, ll> cnt;
  rep(i, N){
    cin >> A;
    cnt[A]++;
  }

  ll ans = 1;

  rep(i, N){
    ans = (ans * cnt[absdif(N - 1 - i, i)]) % MOD;
    cnt[absdif(N - 1 - i, i)]--;
  }

  cout << ans << endl;
  
  return 0;
}