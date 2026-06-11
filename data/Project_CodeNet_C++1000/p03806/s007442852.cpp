#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;

int dp[45][405][405];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, ma, mb;
  cin >> n >> ma >> mb;

  rep(i, n) rep(j, 405) rep(k, 405) {
    dp[i][j][k] = INF;
  }
  dp[0][0][0] = 0;
  rep(i, n) {
    int a, b, c;
    cin>>a>>b>>c;
    rep(j, 405) rep(k, 405) {
      if (j >= a && k >= b) {
        dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a][k-b] + c);
      } else {
        dp[i+1][j][k] = dp[i][j][k];
      }
    }
  }
  int res = INF;
  rep(j, 405) rep(k, 405) {
    if(j != 0 && k != 0 && j*mb == k*ma) {
      res = min(res, dp[n][j][k]);
    }
  }
  cout << (res==INF?-1:res) << endl;
}