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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<long> c(n);

  rep(i, n) {
    int p;
    cin >> p;
    c[p-1] = i;
  }

  vector<long> asum(n+1);
  vector<long> bsum(n+1);

  asum[0] = 0;
  bsum[n] = 0;
  rep(i, n) {
    asum[i+1] = asum[i] + c[i];
  }
  rep(i, n) {
    bsum[n-i-1] = bsum[n-i] + c[n-i-1];
  }

  vector<long> a(n);
  vector<long> b(n);

  rep(i, n) {
    a[i] = i+1 + asum[i+1];
    b[n-i-1] = i+1 + bsum[n-i-1];
  }

  rep(i, n) {
    cout << a[i] << " ";
  }
  cout << endl;
  rep(i, n) {
    cout << b[i] << " ";
  }
  cout << endl;
}
