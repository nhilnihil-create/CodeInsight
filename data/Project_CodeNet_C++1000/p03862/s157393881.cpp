#include <bits/stdc++.h>
using namespace std;

#define Task "abc"
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  int n, x; cin >> n >> x;
  vector<ll> a(n+1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2; i <= n; ++i){
    ll d = max(a[i] + a[i-1] - x, 0ll);
    ans += d;
    a[i] = max(a[i] - d, 0ll);
  }
  cout << ans;
}

