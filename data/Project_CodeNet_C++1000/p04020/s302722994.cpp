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
const int inf = 1e9 + 7;
const double PI = 3.14159265359;
signed main () {
    ios_base::sync_with_stdio(NULL);  cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int pr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = ni();
        ans += (x - 1) / 2;
        if (x == 0) x = 0;
        else if (x % 2 == 0) x = 2;
        else x = 1;
        if (x == 2) {
            if (pr == 2) {
                ans += 2;
                pr = 0;
            }
            else if (pr == 1) {
                ans += 1;
                pr = 1;
            }
            else {
                pr = 2;
            }
        }
        else if (x == 1) {
            if (pr == 2) {
                ans += 1;
                pr = 1;
            }
            else if (pr == 1) {
                ans += 1;
                pr = 0;
            }
            else {
                pr = 1;
            }
        }
        else {
            ans += pr / 2;
            pr = 0;
        }
    }
    ans += pr / 2;
    cout << ans << '\n';
    return 0;
}


















