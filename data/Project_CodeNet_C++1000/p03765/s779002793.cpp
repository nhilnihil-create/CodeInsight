#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  s = " " + s, t =  " " + t;
  vector<int> s1(n + 5), s2(m + 5);
  for (int i = 1; i <= n; ++i){
    if (s[i] == 'A') s1[i] = s1[i - 1] + 2;
    else s1[i] = s1[i - 1] + 1;
  }
  for (int i = 1; i <= m; ++i){
    if (t[i] == 'A') s2[i] = s2[i - 1] + 2;
    else s2[i] = s2[i - 1] + 1;
  }
  int q; cin >> q;
  while (q--){
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ss = s1[r1] - s1[l1 - 1];
    int ts = s2[r2] - s2[l2 - 1];
    if (ss % 3 == ts % 3) cout << "YES\n";
    else cout << "NO\n";
  }
}
