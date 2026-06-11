
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
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 1e5;
const ll INF = 1e18;
int N;
int a[MAX_N];
char op[MAX_N];
ll dp[MAX_N][3];


int main() {
  cin >> N;
  op[0] = '+';
  cin >> a[0];
  for (int i = 1; i < N; ++i) {
    char c;
    cin >> op[i] >> a[i];
  }

  dp[0][0] = a[0]; dp[0][1] = -INF; dp[0][2] = -INF;
  for (int i = 1; i < N; ++i) {
    if (op[i] == '+') {
      dp[i][0] = max(dp[i-1][0] + a[i], max(dp[i-1][1] - a[i], dp[i-1][2] + a[i]));
      dp[i][1] = max(dp[i-1][1] - a[i], dp[i-1][2] + a[i]);
      dp[i][2] = dp[i-1][2] + a[i];
    } else {
      dp[i][0] = max(dp[i-1][0] - a[i], max(dp[i-1][1] + a[i], dp[i-1][2] - a[i]));
      dp[i][1] = max(dp[i-1][0] - a[i], max(dp[i-1][1] + a[i], dp[i-1][2] - a[i]));
      dp[i][2] = max(dp[i-1][1] + a[i], dp[i-1][2] - a[i]);
    }
  }

  cout << dp[N-1][0] << endl;

  return 0;
}
