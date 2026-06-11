#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <tuple>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll max3(ll a, ll b, ll c){return max(a, max(b, c));};
ll min3(ll a, ll b, ll c){return min(a, min(b, c));};
ll max4(ll a, ll b, ll c, ll d){return max(max(a, b), min(c, d));};
ll min4(ll a, ll b, ll c, ll d){return min(min(a, b), min(c, d));};
ll max5(ll a, ll b, ll c, ll d, ll e){return max(max(a, b), max3(c, d, e));};
ll min5(ll a, ll b, ll c, ll d, ll e){return min(min(a, b), min3(c, d, e));};

const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
ll MOD = 1000000007;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

ll kai_mod(ll x){
  if(x == 0) return 1;
  return x * kai_mod(x-1) % MOD;
}

/*
//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}
*/

int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N){
    cin >> A[i];
    A[i]--;
  }

  vector<ll> ef(2 * M, 0), re(2 * M, 0), ans(M, 0);
  ll x = 0;
  rep(i, N-1){

    ll s = A[i], t = A[i+1];
    if(s > t) t += M;
    ll need = t - s;
    if(t >= M && need >= 2){
      x += 1 + t - M;
    }else{
      x += need;
    }
    if(need <= 1) continue;
    ef[s+2]++;
    ef[t+1]--;
    re[t+1] -= need - 1;
  }

  rep(i, 2 * M - 1){
    ef[i+1] += ef[i];
  }

  rep(i, M){
    ef[i] += ef[i+M];
    re[i] += re[i+M];
  }


  ans[0] = x;
  rep(i, M-1){
    ans[i+1] = ans[i] - ef[i+1] - re[i+1];
  }

  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;

}
