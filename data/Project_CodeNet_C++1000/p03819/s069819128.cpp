#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

class fenwick_tree
{
public:
  vector<int> cnt; int n;
  fenwick_tree(int _n)
  {
    n = _n;
    cnt.assign(n + 5, 0);
  }
  void update(int i, int v)
  {
    for (; i <= n; i += i & -i)
      cnt[i] += v;
  }
  int sum(int i)
  {
    int res = 0;
    for (; i; i -= i & -i)
      res += cnt[i];
    return res;
  }
};

const int maxn = 1e5 + 5;

int N, M;
vector<int> d[maxn];
vector<int> era[maxn];
int ans[maxn], add[maxn];

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  for (int i = 1; i < maxn; ++i){
    for (int j = i; j < maxn; j += i){
      d[j].pb(i);
    }
  }
  cin >> N >> M;
  fenwick_tree ft(M);
  while (N--){
    int l, r; cin >> l >> r;
    ++add[l]; era[r].pb(l);
  }
  for (int i = 1; i <= M; ++i){
    ft.update(i, add[i]);
    for (int x : d[i]){
      ans[x] += ft.sum(i) - ft.sum(i - x);
    }
    for (int x : era[i]){
      ft.update(x, -1);
    }
  }
  for (int i = 1; i <= M; ++i){
    cout << ans[i] << '\n';
  }
}
