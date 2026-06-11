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

const int N = 3001;
const int inf = 1e9 + 7;
const double PI = 3.14159265359;

signed main () {
    ios_base::sync_with_stdio(NULL);  cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back({ni() - 1, i});
    }
    sort(all(v));
    multiset <int> st;
    st.insert(-1);
    st.insert(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (v[i].second - *prev(st.lower_bound(v[i].second))) * (*st.lower_bound(v[i].second) - v[i].second) * (i + 1);
        st.insert(v[i].second);
    }
    cout << ans << '\n';
    return 0;
}


















