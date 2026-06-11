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

int main(){
  ll N;
  cin >> N;

  ll sqN = (ll)(sqrt(N)) + 1;
  
  vl primes(N + 1, 1);
  primes[0] = primes[1] = 0;
  rep2(i, 2, sqN + 1){
    if(primes[i] != 0){
      ll j = 2;
      while(i*j <= N){
	primes[i*j] = 0;
	j++;
      }
    }
  }

  ll ans = 1;
  
  rep(i, N + 1){
    if(primes[i] == 0) continue;

    ll cnt = 0;
    ll j = i;

    while(j <= N){
      cnt += N / j;
      j *= i;
    }

    ans = ans * (cnt + 1) % MOD;
  }

  cout << ans << endl;
  
  return 0;
}