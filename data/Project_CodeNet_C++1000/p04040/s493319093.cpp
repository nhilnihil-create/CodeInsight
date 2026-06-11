#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>
#include <random>
#define INF 1000000000
#define LINF 9000000000000000000
// #define mod  1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/
#define int64_t long long
#define int long long

struct Combination
{
  int mod;
  vector< int64_t > mfact, rfact;

  Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod)
  {
    mfact[0] = 1;
    for(int i = 1; i < mfact.size(); i++) {
      mfact[i] = mfact[i - 1] * i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for(int i = sz - 1; i >= 0; i--) {
      rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
  }

  int64_t fact(int k) const
  {
    return (mfact[k]);
  }

  int64_t pow(int64_t x, int64_t n) const
  {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }

  int64_t inv(int64_t x) const
  {
    return (pow(x, mod - 2));
  }
  
  int64_t P(int n, int r) const
  {
    if(r < 0 || n < r) return (0);
    return (mfact[n] * rfact[n - r] % mod);
  }

  int64_t C(int p, int q) const
  {
    if(q < 0 || p < q) return (0);
    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
  }

  int64_t H(int n, int r) const
  {
    if(n < 0 || r < 0) return (0);
    return (r == 0 ? 1 : C(n + r - 1, r));
  }
};


signed main(){
  ll H, W, A, B;
  Combination cmb(200002, 1000000007);
  const ll mod = 1000000007;
  cin >> H >> W >> A >> B;

  ll ans = 0;
  for(ll i = B + 1; i <= W; i++){		      
    ans = (ans + cmb.C(i  - 1+ H - A - 1, i - 1) * cmb.C(W - i  + A - 1, A - 1)) % mod;
  }
  cout << ans << endl;
  return 0;
}