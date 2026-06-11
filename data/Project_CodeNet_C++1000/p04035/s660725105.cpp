#pragma GCC optimize ("O3")
#pragma GCC target (sse, sse1, sse2, tune=native, popcnt)

#include <bits/stdc++.h>
/*
const int MAX_MEM = 3e8;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete(void *) {}
*/
using namespace std;

#define loop(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define vec vector
#define paii pair<int, int>
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define SZ(x) (int)x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define ll long long

#define int long long

const int inf = 1e17 + 47, MAXN = 5e5 + 47, mod = 1e9 + 7, N = 201;

mt19937 rnd(time(0));

int n, s;
vec<int> val;

void solve() {
    cin >> n >> s;
    val.resize(n);
    loop(i, n) cin >> val[i];
    FOR(i, 1, n) {
        if(val[i] + val[i - 1] >= s) {

            cout << "Possible" << endl;
            loop(j, i - 1) cout << j + 1 << endl;

            for(int j = n - 2; j >= i; --j) cout << j + 1 << endl;
            cout << i << endl;
            return ;
        }
    }
    cout << "Impossible" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    #ifdef COFFEE_MACHINE
        freopen("input.cpp", "r", stdin);
        freopen("output.cpp", "w", stdout);
    #endif // COFFEE_MACHINE

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
