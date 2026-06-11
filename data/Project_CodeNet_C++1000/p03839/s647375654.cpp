#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
ll pf[N];
ll sf[N];
ll a[N];
ll pref[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  for(int i = 1; i <= n; i ++ ){
    pf[i] = max(pf[i - 1], pf[i - 1] + a[i]);
  }
  for(int i = n; i >= 1; i -- ){
    sf[i] = max(sf[i + 1], sf[i + 1] + a[i]);
  }
  int l, r;
  ll res = 0;
  for(int i = 1; i <= n - k + 1; i ++ ){
    l = i;
    r = i + k - 1;
    res = max(res, max(pref[r] - pref[l - 1],0ll) + pf[l - 1] + sf[r + 1]);
  }
  cout << res << "\n";
  return 0;
}
