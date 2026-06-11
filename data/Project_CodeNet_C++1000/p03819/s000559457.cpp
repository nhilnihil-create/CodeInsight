#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <numeric>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define pb push_back
#define int long long
#ifdef int
const long long INF = LLONG_MAX / 10;
#else
const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<ll> > mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;
const int dx[9] = {-1, 0, 0, 1, -1, -1, 1, 1, 0};
const int dy[9] = {0, -1, 1, 0, -1, 1, -1, 1, 0};


//BIT [1,n]
const int MAX_N = 202020;
int bit[MAX_N + 1], n = 202020;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}


int N, M;
vint lis[101010];

signed main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M;
  REP(i,N) {
    int l, r;
    cin >> l >> r;
    r++;
    lis[r-l].pb(l);
  }

  int latte = N;
  for (int d=1; d<=M; d++) {
    for (auto l : lis[d]) {
      int r = l + d;
      add(r, -1);
      add(l, 1);
    }
    latte -= lis[d].size();
    int ans = latte;
    for (int x=d; x<=M; x+=d) ans += sum(x);
    cout << ans << endl;
  }
}