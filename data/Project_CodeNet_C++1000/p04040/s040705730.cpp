#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const ll linf = 1e18;
const ll mod = 1e9 + 7;

ll power(ll a, ll b)
{
   if(b == 1) return a; 

   return (power(a*a%mod, b/2) * (b%2 ? a : 1)) % mod;
}

int main()
{
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  ll fac[300000], inv[100000], finv[100000];
  fac[0] = inv[0] = finv[0] = 1;
  rep(i, 3e5-1) fac[i+1] = fac[i]*(i+1)%mod;
  rep(i, 1e5) inv[i] = power(i, mod-2);
  rep(i, 1e5-1) finv[i+1] = finv[i] * inv[i+1] % mod;

  ll ans = 0;
  rep(i, h-a){
    ll cnt = 1;

    cnt *= fac[i+b-1];
    cnt %= mod;

    cnt *= finv[i];
    cnt %= mod;

    cnt *= finv[b-1];
    cnt %= mod;

    cnt *= fac[h-i-1+w-b-1];
    cnt %= mod;

    cnt *= finv[h-i-1];
    cnt %= mod;

    cnt *= finv[w-b-1];
    cnt %= mod;

    ans += cnt;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
