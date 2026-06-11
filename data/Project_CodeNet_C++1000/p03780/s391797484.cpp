#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const int maxn = 5e3 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int f[maxn][maxn];
int n, k;
int a[maxn];

bool ok(int id){
  for (int i = 0; i <= n; ++i) for (int j = 0; j <= k; ++j)
    f[i][j] = 0;

  f[0][0] = 1;
  for (int i = 1; i <= n; ++i){
    for (int val = 0; val <= k; ++val) f[i][val] |= f[i-1][val];
    if (i == id) continue;
    for (int val = a[i]; val <= k; ++val){
      f[i][val] |= f[i-1][val-a[i]];
    }
  }

  for (int val = 1; val <= k; ++val) f[n][val] += f[n][val-1];
  int l = max(0, k - a[id]), r = k - 1;
  if (l == 0) return f[n][r] == 0;
  return (f[n][r] - f[n][l-1]) == 0;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  int l = 1, r = n;
  while (l <= r){
    int mid = (l + r) / 2;
    if (ok(mid)) l = mid + 1;
    else r = mid - 1;
  }
  cout << l - 1;
}


