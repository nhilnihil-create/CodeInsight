#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 200010
#define foru(i, l, r) for(int i = (l); i <= (r); ++i)
#define ford(i, l, r) for(int i = (l); i >= (r); --i)

int n;
ll k;
ll pre[maxn];
int fw[maxn];

void updatefw(int i) {
  for (; i < maxn; i += i & -i) fw[i]++;
}

int getfw(int i) {
  int ret = 0;
  for (; i > 0; i -= i & -i) ret = ret + fw[i];
  return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// PERSUBARR
    //freopen("PERSUBARR.inp", "r", stdin); freopen("PERSUBARR.out", "w", stdout);
    cin >> n >> k;
    ll ans = 0;
    vector<ll> com;
    com.push_back(0);
    for (int i = 1; i <= n; ++i) {
      ll x;
      cin >> x;
      x = x - k;
      pre[i] = pre[i-1] + x;
      com.push_back(pre[i]);
    }
    sort(com.begin(), com.end());

    for (int i = 0; i <= n; ++i) {
      pre[i] = lower_bound(com.begin(), com.end(), pre[i]) - com.begin() + 1;
    }
    updatefw(pre[0]);
    for (int i = 1; i <= n; ++i) {
      ans = ans + getfw(pre[i]);
      updatefw(pre[i]);
    }
    cout << ans;
    return 0;
}
