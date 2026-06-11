#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int INF = 1e18;
const int M = 1e9 + 7;
//__int128
const int maxn = 5e5;
int dp[maxn][20];
int x[maxn];
signed main()
{
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int l;
  cin >> l;
  for(int i = 0; i < n; ++i) {
    dp[i][0] = upper_bound(x, x + n, x[i] + l) - x - 1;
  }
  int m = 0;
  for(int j = 1; (1 << j) < n; ++j, ++m) {
    for(int i = 0; i < n; ++i) {
      if(i + (1 << j) >= n) dp[i][j] = n - 1;
      dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }  
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if(l > r) swap(l, r);
    int res = 0;
    while(1) {
      int time = lower_bound(dp[l], dp[l] + m, r) - dp[l];
      if(time == 0) {
        ++res;
        break;
      } else {
        time--;
        res += 1 << time;
        l = dp[l][time];
      }
    }
    cout << res << endl;
  }
  return 0;
}