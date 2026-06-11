#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))

const int INF = 1000000009;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 2e5;

ll N, K;
ll I, O, T, J, L, S, Z;

int main() {
  cin >> I >> O >> T >> J >> L >> S >> Z;
  ll ans = (I/2+J/2+L/2)*2;
  if (I>0 && J>0 && L>0) ans = max(ans, 3+((I-1)/2+(J-1)/2+(L-1)/2)*2);
  cout << O+ans << endl;

  return 0;
}