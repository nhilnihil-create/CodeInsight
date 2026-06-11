///#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
///#define double long double
#define all(x) (x).begin(), (x).end()
#define finout(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define X first
#define Y second

using namespace std;
const int MOD = 1e9 + 7;

typedef pair <int, int> pii;
typedef vector <int> vi;
inline int ni() {int x; cin >> x; return x;}
template <class T>
inline T nt() {T x; cin >> x; return x;}
inline void print(){}
template<typename T, typename ...TAIL>
inline void print(const T &t, TAIL... tail) {cout << t; print(tail...);}
inline void input() {return;}
template<typename T, typename ...TAIL>
inline void input(T &t, TAIL&... tail) {cin >> t; input(tail...);}

const int N = 2 * 1e5 + 1;
const int inf = 1e18 + 7;
const double PI = 3.14159265359;


int cost[N];
int best[N];

signed main () {
    ios_base::sync_with_stdio(NULL);  cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vi v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        v.push_back(ni());
        res += v[i];
        cost[i] = v[i];
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cost[i] > v[(i - j + n) % n]) {
                cost[i] = v[(i - j + n) % n];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cost[i];
        }
        ans += j * x;
        res = min(res, ans);
    }
    cout << res << '\n';
    return 0;
}
















