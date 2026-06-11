// In The Name Of Allah

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pp pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int maxx = 2e3 + 19;
const int inf = 1e18 + 19;
const int mod = 1000000007LL;

int n, x;
int a[maxx] = {}, b[maxx] = {}, ans = inf;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];
    for (int i = 0; i < n; i++) {
        int tmp = i * x;
        for (int j = 0; j < n; j++) {
            b[j] = min(b[j], a[(j + n - i) % n]);
            tmp += b[j];
        }
        ans = min(ans, tmp);
    }
    cout << ans;
    return 0;
}
