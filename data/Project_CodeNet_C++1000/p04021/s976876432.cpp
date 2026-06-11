#pragma GCC optimize("O3")
#include <bits/stdc++.h>
//#define int long long
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

const int N = 2 * 1005001;
const int inf = 1e9 + 7;
const double PI = 3.14159265359;

signed main () {
    ios_base::sync_with_stdio(NULL);  cin.tie(0); cout.tie(0);
    int n = ni();
    vi v;
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        v.push_back(ni());
        mp[v[i]] = i % 2;
    }
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != mp[v[i]]) ans++;
    }
    ans = (ans + 1) / 2;
    cout << ans << '\n';
}


















