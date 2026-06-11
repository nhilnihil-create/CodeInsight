#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;
using ld = long double;
const ll mod =  1000000007;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

int bsearch(const vector<ll>& a, ll x){
  int lft = 0;
  int rgt = a.size();
  while (rgt - lft > 1) {
    int mid = (lft + rgt) / 2;
    if(a[mid] < x) {
      lft = mid;
    }
    else {
      rgt = mid;
    }
  }
  return lft;
}


signed main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a;
    REP(i, n) a.push_back(1 + (i+1) * 20000);
    vector<ll> b = a;
    reverse(all(b));
    REP(i, n) {
      int p;
      cin >> p;
      p--;
      a[p] += i;
    }
    REP(i, n) cout << a[i] << " "; cout << endl;
    REP(i, n) cout << b[i] << " "; cout << endl;
  return 0;
}
