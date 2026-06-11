///#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
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

vi v;
int L;
int go[N][20];

bool check(int x, int a, int b) {
    for (int i = 19; i >= 0; i--) {
        if (x >= (1<<i)) {
            x -= 1<<i;
            a = go[a][i];
        }
    }
    return a >= b;
}

signed main () {
    ios_base::sync_with_stdio(NULL);  cin.tie(0); cout.tie(0);
    int n = ni();
    for (int i = 0; i < n; i++) v.push_back(ni());
    L = ni();

    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (v[m] - v[i] <= L)
                l = m;
            else
                r = m;
        }
        go[i][0] = l;
    }
    go[n][0] = n;
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i <= n; i++) {
            go[i][j] = go[go[i][j - 1]][j - 1];
        }
    }



    int Q = ni();
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        int ans = 0;
        int l = 0, r = b - a + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m, a, b)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (check(l, a, b)) r = l;
        cout << r << '\n';
    }
}




/*
5
1 2 3 4 5
2
1
1 5

*/









