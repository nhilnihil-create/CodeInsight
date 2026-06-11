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


const int MAXN = 100;
//#define int long long
const int INF = 1e9;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  priority_queue<pair<int, int>> q;
  ll ans = 0LL, prans = 0LL;
  for (int i = n-1; i > -1; i--){
    int cnt = 1;
    while (!q.empty() && q.top().ff > a[i]) {
      cnt += q.top().ss;
      prans -= (ll)q.top().ss * (ll)q.top().ff;
      q.pop();
    }
    prans += (ll)cnt * (ll)a[i];
    ans += prans;
    q.push(mp(a[i], cnt));
    //cerr << "i: " << prans << '\n';
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
