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
  
  map<int, int> m;
  for (int i = 0; i < n; i++){
    if (!m.count(a[i])) m[a[i]] = 0;
    m[a[i]]++;
  }
  vector<pair<int, int>> v;
  for (auto i : m) v.eb(i);

  if (v[0].ss > 2){
    cout << "Impossible\n";
    return;
  }
  int d = 0;
  if (v[0].ss == 2) d++;

  for (int i = 1; i < (int) v.size(); i++){
    if (v[i].ff - 1 > v[i-1].ff || v[i].ss < 2){
      cout << "Impossible\n";
      return;
    }

    d+=2;
  }

  if (v.back().ff != d){
    cout << "Impossible\n";
    return;
  }

  cout << "Possible\n";
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
