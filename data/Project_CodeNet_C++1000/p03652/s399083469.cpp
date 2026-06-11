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
pair<int, int> culc(vector<vector<int>> a, vector<bool> canUse) {

  int n = a.size();
  int m = a[0].size();
  vector<int> score(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!canUse[a[i][j]]) continue;
      score[a[i][j]]++;
      break;
    }
  }

  int val = 0;
  int id;
  for (int i = 0; i < m; i++) {
    if (val < score[i]) {
      val = score[i];
      id = i;
    }
  }

  return make_pair(val, id);
}

int main() {
  
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  
  vector<bool> canUse(m, true);
  int ans = n + 1;
  while (1) {

    // 全部使えないなら，終わり
    bool end = true;
    for (int i = 0; i < m; i++) {
      if (canUse[i]) end = false;
    }
    if (end) break;

    int tmp;
    int id;
    tie(tmp, id) = culc(a, canUse);
    ans = min(ans, tmp);
    canUse[id] = false;
  }

  cout << ans << endl;
  return 0;
}
