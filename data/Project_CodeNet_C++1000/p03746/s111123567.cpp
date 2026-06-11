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
#define INF (1e18)
#define PI (acos(-1))

#define fillInt(xs)        \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%ld", &xs[i]);
#define fillDouble(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%lf", &xs[i]);
#define fillString(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;
const int MAX_V = 100005;

bool used[MAX_V];
vector<int> G[MAX_V];

vector<int> lv;
vector<int> rv;

void dfsl(int s) {
  used[s] = true;
  for(int v: G[s]) {
    if (used[v]) continue;
    lv.push_back(v);
    dfsl(v);
    break;
  }
}

void dfsr(int s) {
  used[s] = true;
  for(int v: G[s]) {
    if (used[v]) continue;
    rv.push_back(v);
    dfsr(v);
    break;
  }
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n, m;
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  lv.push_back(0);
  dfsl(0);
  dfsr(0);

  cout << lv.size() + rv.size() << endl;
  rep(i, lv.size()) {
    cout << lv[lv.size() - i - 1] + 1 << endl;
  }
  rep(i, rv.size()) {
    cout << rv[i] + 1 << endl;
  }
}
