#include <bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define MAXN 200005
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> intpair;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
inline int lowbit(int x){
    return x & (-x);
}
inline int modadd(int x, int y){
    return (x + y >= MOD ? x + y - MOD: x + y);
}
inline int sgn(int x){
    return (x < 0 ? -1: (x > 0 ? 1: 0));
}
template<typename T>
T gcd(T a, T b){
    return (!b) ? a: gcd(b, a % b);
}
int poww(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD, b >>= 1;
    }
    return res;
}
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/

ll n, x;
ll solve(ll b, ll a){
    if (b <= a){
        if (a == b) return 2 * a;
        return a + b + solve(a - b, b);
    }
    if (b % a == 0) return 2ll * b;
    ll t = b / a;
    return (2 * t + 1) * a + b % a + solve(a - (b % a), b % a);
}
void init(){
    scanf("%lld%lld", &n, &x);
}
void solve(){
    ll ans = x + solve(x, n - x);
    printf("%lld\n", ans);
}
int main(){
    int T = 1;
    while (T--){
        init();
        solve();
    }
    return 0;
}