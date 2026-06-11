
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 100000, MAX_M = 100000;
int N, M;
int a[MAX_N];
ll dp[MAX_M+1];

// nを初期化するのを忘れずに
int BIT[MAX_M+10], n;

int sum(int i) {
  int res = 0;
  while (i > 0) {
    res += BIT[i];
    i -= i & (-i);
  }
  return res;
}


void add(int i, int x) {
  while (i <= n) {
    BIT[i] += x;
    i += i & (-i);
  }
}

int main() {
  cin >> N >> M;
  rep(i,N) cin >> a[i];
  n = M+10;

  for (int i = 0; i+1 < N; ++i) {
    if (a[i] < a[i+1]) {
      add(a[i]+1, 1);
      add(a[i+1], -1);
    } else {
       add(1, 1);
       add(a[i+1], -1);
       add(a[i]+1, 1);
    }
  }


  vector<pii> vp;
  for (int i = 1; i < N; ++i) {
    vp.push_back(pii(a[i], i));
  }

  sort(all(vp));

  for (int i = 0; i+1 < N; ++i) {
    if (a[i] < a[i+1]) dp[1] += a[i+1]-a[i];
    else dp[1] += a[i+1];
  }

  for (int m = 1; m < M; ++m) {
    dp[m+1] = dp[m]-sum(m);
    for (int i = lower_bound(all(vp), pii(m, 0)) - vp.begin(); i < vp.size() && vp[i].fi == m ; ++i) {
      dp[m+1] += (a[vp[i].sc]+M-a[vp[i].sc - 1])%M - 1;
    }
  }

  ll ans = 1e18;
  for (int m = 1; m <= M; ++m) {
    ans = min(ans, dp[m]);
  }

  cout << ans << endl;

  return 0;
}

