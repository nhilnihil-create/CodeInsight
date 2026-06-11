//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 503;
int n, m, h, w, a[N][N], dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m >> h >> w;
    if (n % h == 0 && m % w == 0) {
        cout << "No";
        return 0;
    }
    if (m % w) {
        dp[m] = 1;
        for (int i = w; i <= m; i += w) {
            dp[i] = dp[i - w] - 1;
        }
        for (int i = m - 1; i > 0; i--) {
            if (i % w && i + w <= m) {
                dp[i] = dp[i + w] + 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            int x = dp[i] - dp[i - 1];
            for (int j = h; j <= n; j += h) {
                a[j][i] = x;
            }
        }
    }   else {
        dp[n] = 1;
        for (int i = h; i <= n; i += h) {
            dp[i] = dp[i - h] - 1;
        }
        for (int i = n - 1; i > 0; i--) {
            if (i % h && i + h <= n) {
                dp[i] = dp[i + h] + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            int x = dp[i] - dp[i - 1];
            for (int j = w; j <= m; j += w) {
                a[i][j] = x;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
