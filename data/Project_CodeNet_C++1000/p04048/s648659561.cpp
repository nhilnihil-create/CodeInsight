#include <bits/stdc++.h>
#define forn(x, n)              for (int x = 0; x < n; x++)
#define forr(x, n)              for (int x = n; x >= 0; x--)
#define fore(x, a, b, c)        for (int x = a; x <= b; x += c)
#define forre(x, a, b, c)       for (int x = a; x >= b; x -= c)
#define clr                     cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define all(container)          (container).begin(), (container).end()
#define rall(container)         (container).rbegin(), (container).rend()
#define FILL(x, val)            memset(x, val, sizeof(x))
#define pb                      push_back
#define eb                      emplace_back
#define fi                      first
#define se                      second
#define mod                     (int)1000000007
#define INF                     (int)0x3f3f3f3f

using namespace std;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }  

typedef long long ll; 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x; cin >> n >> x;
    ll gg = __gcd(n, x);
    ll ans = 3 * (n - gg);
    cout << ans << '\n';
    return 0;
}