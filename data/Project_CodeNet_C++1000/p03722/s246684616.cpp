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

struct edge {
  int to;
  long cost;
};

const int MAX_V = 100005;
vector<edge> G[MAX_V];
long d[MAX_V];
int n, m;
vector<long> dn;

bool bellmanFord(int s) { 
  fill(d, d+n, -INF*INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    dn.push_back(d[n-1]);
    for (int v = 0; v < n; v++) {
      for (int k = 0; k < G[v].size(); k++) {
        edge e = G[v][k];
        if (d[v] != -INF*INF && d[e.to] < d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          if (i == n - 1) {
            if (dn[dn.size()-1] > dn[dn.size()-2]) {
              return true;
            } else {
              return false;
            }
          }
        }
      }
    }
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  rep(i, m) {
    int a, b;
    long c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back({b, c});
  }

  bool isInf = bellmanFord(0);

  if (isInf) {
    cout << "inf" << endl;
  } else {
    cout << d[n-1] << endl;
  }
}