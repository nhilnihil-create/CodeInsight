#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */

int main(){
    int n; cin >> n;
    vector<lint> t(n), a(n);
    vector<lint> l(n), u(n);
    rep(i, n){
        l[i] = 1; u[i] = 1e9;
    }

    rep(i, n){
        cin >> t[i];
        if(i != 0 && t[i-1] == t[i]) u[i] = t[i];
        else{
            l[i] = t[i]; u[i] = t[i];
        }
    }

    rep(i, n) cin >> a[i];
    repr(i, n){
        if(i != n-1 && a[i] == a[i+1]) u[i] = min(u[i], a[i]);
        else{
            l[i] = max(l[i], a[i]);
            u[i] = min(u[i], a[i]);
        }
        if(l[i] > u[i]){
            out(0); return 0;
        }
    }

    lint ans = 1;
    rep(i, n){
        ans *= u[i] - l[i] + 1;
        ans %= MOD;
    }
    out(ans);
}
