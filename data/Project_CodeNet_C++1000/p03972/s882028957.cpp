#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif

/*
Task: https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c
C - Gr-idian MST
*/


const int MAXN = 100;
//#define int long long
const int INF = 1e9;

void solve(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n + m);
  for (int i = 0; i < n; i++) {
    cin >> a[i].ff;
    a[i].ss = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> a[n+i].ff;
    a[n+i].ss = 2;
  }

  sort(a.begin(), a.end());

  int cur = 0;
  ll ans = 0;
  n++, m++;
  while (cur < (int)a.size()){
    if (a[cur].ss == 1){
      ans += (ll)a[cur].ff * (ll)m;
      n--;
    } else {
      ans += (ll)a[cur].ff * (ll)n;
      m--;
    }
    cur++;
  }

  cout << ans << '\n';
}

signed main()
{
    #ifdef FILEIO
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
