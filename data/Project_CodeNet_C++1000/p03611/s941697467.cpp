#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll n;
    cin >> n;
    map<ll, ll>m;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        m[x]++;
    }

    ll ans = 0;
    for (ll i = 2; i <= 100001; i++) {
       ll tmp = 0;
        tmp += m[i] + m[i - 1] + m[i - 2];
        ans = max(ans , tmp);
    }

    cout << ans << endl;
    return 0;
}
