/// nyaaaaa

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = (int) 3e5 + 5;
const int inf = (int) 1e9 + 7;

int n, l;
int a[N];
ll p[N];
set<pii> s;
set<int> can;

ll sum(pii x) {
  return p[x.second] - p[x.first - 1];
}

int main() {
  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
    s.insert(make_pair(i, i));
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] + a[i + 1] >= l) {
      can.insert(i);
    }
  }
  vector<int> ans;
  while (!can.empty()) {
    int p = *can.begin();
    can.erase(can.begin());
    auto cur = prev(s.upper_bound(make_pair(p, inf)));
    if (next(cur) != s.end()) {
      pii F = *cur;
      pii S = *next(cur);
      s.erase(F);
      s.erase(S);
      ans.push_back(F.second);
      s.insert(make_pair(F.first, S.second));
      cur = prev(s.upper_bound(make_pair(F.first, inf)));
      if (next(cur) != s.end() && sum(*cur) + sum(*next(cur)) >= l) {
        can.insert(cur -> first);
      }
      if (cur != s.begin() && sum(*cur) + sum(*prev(cur)) >= l) {
        can.insert(prev(cur) -> first);
      }
    }
  }
  if (sz(s) != 1) {
    cout << "Impossible\n";
    return 0;
  }
  reverse(ans.begin(), ans.end());
  cout << "Possible\n";
  for (int i : ans) {
    cout << i << "\n";
  }

  return 0;
}
