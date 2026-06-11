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
    int n, m; cin >> n >> m;
    vector<int> x(n), y(m), z(m); rep(i, n) cin >> x[i];

    rep(i, n) y[x[i] % m]++;

    sort(all(x));
    for(int i = 0; i < n-1; ){
        if(x[i] == x[i+1]){
            z[x[i] % m]++;
            i += 2;
        }
        else i++;
    }

    int ans = 0;
    for(int k = 0; k <= m / 2; k++){
        if(k == 0 || k * 2 == m) ans += y[k] / 2;
        else{
            if(y[k] >= y[m-k]) ans += y[m-k] + min((y[k]-y[m-k])/2, z[k]);
            else ans += y[k] + min((y[m-k]-y[k])/2, z[m-k]);
        }
    }
    
    out(ans);
}