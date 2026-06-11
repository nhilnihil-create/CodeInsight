#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define dbg(x) cout << #x << " = " << x << endl
#define F_OR(i, a, b, s) for(int i = (a); (s) > 0 ? i < (b) : i >= (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define ite(i, x) for(auto& i: x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;


int main() {
    #ifdef LOCAL
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int ans = 1;
    bool a, b;
    a = b = 0;
    int ant; cin >> ant;
    FOR(i, n - 1){
        int m; cin >> m;
        if(m > ant) a = 1;
        if(m < ant) b = 1;
        if(a && b) a = b = 0, ++ans;
        ant = m;
    }
    cout << ans << endl;
    return 0;
}
