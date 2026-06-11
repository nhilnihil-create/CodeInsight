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

string dp[10020];

const int MAX_N = 55;

ll pascal[MAX_N][MAX_N];

void initFact() {
  for (int i = 1; i <=MAX_N; i++) {
      for (int j = 1; j <= MAX_N; j++) {

          if (j == 1)                 // 行の左端は 1
              pascal[i][j] = 1;

          else if (j == i) {          // 行の右端も 1
              pascal[i][j] = 1;
              break;        // 右端まで計算したので内側のループから抜ける
          }
          else              // 行の途中は一つ上の二つの要素の合計
              pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
      }
  }
}

ll combi(int n, int k) {
  return pascal[n+1][k+1];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n, a, b;
  cin >> n >> a >> b;

  vector<long> v(n);
  fillLong(v, n);

  long res = 0;
  sortvinv(v);

  long mn = v[a-1];
  long minCnt = 0;
  long minCntUse = 0;
  rep(i, a) {
    res += v[i];
    if(v[i] == mn) minCntUse++;
  }
  rep(i, n) {
    if(v[i] == mn) minCnt++;
  }
  initFact();

  long cnt = 0;
  if (mn == v[0]) {
    for(int i = a; i <= b; i++) {
      cnt += combi(minCnt, i);
    }
  } else {
    cnt = combi(minCnt, minCntUse);
  }

  printf("%.10f\n", (double)res/a);
  cout << cnt << endl;
}