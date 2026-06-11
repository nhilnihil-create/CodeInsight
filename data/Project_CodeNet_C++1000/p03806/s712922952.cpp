#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i];
        d[i] = b[i]*ma - a[i]*mb;
    }

    vector<map<int, int> > dp(n+1);
    rep(i, n+1){
        for(int j = -105; j <= 105; j++){
            dp[i][j] = MAX;
        }
    }

    rep(i, n) for(int j = -100; j <= 100; j++){
        dp[i+1][j] = dp[i][j];
        if(-100 <= j-d[i] && j-d[i] <= 100){
            if(j-d[i] != 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-d[i]] + c[i]);
            else dp[i+1][j] = min(dp[i+1][j], c[i]);
        }
    }

    if(dp[n][0] == MAX) dp[n][0] = -1;
    out(dp[n][0]);
}