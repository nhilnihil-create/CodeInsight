#include <bits/stdc++.h>

using namespace std;

#define ll long long int 
#define F first
#define S second
#define pb push_back

const ll N = 1e6 + 5;
const ll LOG = 40;
const ll MOD = 1e9 + 7;
const ll OO = 1e9;
ll n, m, a[N], all,  _add[N], cnt[N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i == 1) continue; 
        if (a[i - 1] < a[i]){
            all += a[i] - a[i - 1];
            cnt[a[i - 1] + 1]++, cnt[a[i] + 1]--;
            _add[a[i - 1] + 1] += a[i - 1] + 1ll;
            _add[a[i] + 1] += - a[i - 1] - 1ll;
        }
        if (a[i] < a[i - 1]){
            all += m - a[i - 1] + a[i];
            cnt[1]++, cnt[a[i] + 1]--;
            cnt[a[i - 1] + 1]++;
            _add[1] += -m + a[i - 1] + 1ll;
            _add[a[i] + 1] += m - a[i - 1] - 1ll;
            _add[a[i - 1] + 1] += a[i - 1] + 1ll;
        }
    }
    ll ans = all;
    for (ll i = 1; i <= m; i++){
        cnt[i] += cnt[i - 1];
        _add[i] += _add[i - 1];
        ans = min(ans, all + _add[i] - cnt[i] * i);
    }
    cout << ans << '\n';
    return 0;
}