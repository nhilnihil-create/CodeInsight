#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define vt vector
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a * b / gcd(a, b)
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll N = 1e5 + 5;

ll n, ans;
ll a[N], ps[N];

void solve() {
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }
    for(ll i = 1; i < n; i++) {
        if(ps[i] * 2 < a[i + 1]) {
            ans = 0;
        } else ans++;
    }
    cout << ans + 1 << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}