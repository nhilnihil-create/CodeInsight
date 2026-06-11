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
vector<P> arr[101010];

signed main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M;
  REP(i,N) {
    int l, r;
    cin >> l >> r;
    arr[r-l].pb({l, r});
  }

  int exclude = 0;
  for (int d=1; d<=M; d++) {
    if (d == 1) {
      cout << N << endl;
    } else {
      for (auto p : arr[d-2]) {
        add(p.first, 1);
        add(p.second + 1, -1);
      }
      exclude += arr[d-2].size();
      int ans = N - exclude;
      for (int x=0; x<=M; x+=d) {
        ans += sum(x);
      }
      cout << ans << endl;
    }
  }
}