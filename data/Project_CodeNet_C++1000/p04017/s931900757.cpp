#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  lint n; cin >> n;
  vector<lint> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  lint l; cin >> l;
  lint q; cin >> q;
  vector<lint> a(q);
  vector<lint> b(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
  }


  vector<vector<lint>> dp(32, vector<lint> (n)); // 2^i 日でどこまでいけるか

  // 1 にちでどこまでいけるかの前処理
  for (int i = 0; i < n; i++) {
    lint ok = i;
    lint ng = n;
    while (ng - ok > 1) {
      lint mid = (ok + ng) / 2;
      (x[mid] - x[i] <= l ? ok : ng) = mid;
    }



    dp[0][i] = ok;
  }

  for (int i = 1; i < 32; i++) {
    for (int j = 0; j < n; j++) {
      // cerr << dp[i - 1][j] << " ";
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
    // cerr << endl;
  }

  vector<lint> po(32);
  po[0] = 1;
  for (int i = 1; i < 32; i++) {
    po[i] = po[i - 1] * 2;
  }
  

  // クエリ処理
  for (int i = 0; i < q; i++) {
    // cerr << i << " th query " << endl;
    // a[i] -> b[i] へ行く
    lint cur = a[i];
    lint ans = 0;
    
    // b[i] 以上にならない最大の日数
    /*
    while (cur < b[i]) {
      lint ok = 0;
      lint ng = 32;
      while (ng - ok > 1) {
        lint mid = (ok + ng) / 2;
        (dp[mid][cur] < b[i] ? ok : ng) = mid;
      }
  
      cur = dp[ok][cur];
      // cerr << ok << " " << cur << endl;
      ans += po[ok];
    } 
    */

    /*
     * 下ってどっちだろ
    大きい方から試して、それを適用して条件を満たさないのなら適用しない
    満たすのなら（2 べきの大小関係とか回数に対して単調なことなどから）適用していい
    みたいな感じで*/

    for (int j = 31; j >= 0; j--) {
      if (dp[j][cur] < b[i]) {
        cur = dp[j][cur];
        ans += po[j];
      }
    }

    cout << ans + 1 << endl;
  }
  return 0;
}
