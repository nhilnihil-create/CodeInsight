#include <bits/stdc++.h>
using namespace std;
#define incant() cin.tie(0), ios::sync_with_stdio(false)
#define int long long
#define double long double
template <class T> using pqueue = priority_queue<T>;
using vint = vector<int>;
using vstr = vector<string>;
using pint = pair<int, int>;
using vp = vector<pint>;
using tint = tuple<int, int, int>;
using vt = vector<tint>;
using mint = map<int, int>;
using dict = map<string, int>;
using sint = set<int>;
using sp = set<pint>;
using qint = queue<int>;
using qp = queue<pint>;
using pqint = pqueue<int>;
using pqp = pqueue<pint>;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define sz(x) x.size()
#define all(x) begin(x), end(x)
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep,)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev,)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
void in(){}
template<typename F, typename... R>
void in(F& f, R&... r){cin >> f, in(r...);}
#define out(x) cout << (x)
#define space() cout << " "
#define indent() cout << '\n'
void print(){}
template<typename F, typename... R>
void print(F& f, R&... r){out(f), space(), print(r...);}
#define printv(x) each(i, x) out(i), space(); indent()
#define debug(x, ...) cerr << __LINE__ << ": " << #x << ": " << (x) << '\n'
#define YN(x) print((x) ? "YES" : "NO")
#define Yn(x) print((x) ? "Yes" : "No")
#define yn(x) print((x) ? "yes" : "no")
#define POS(x) print((x) ? "POSSIBLE" : "IMPOSSIBLE")
#define Pos(x) print((x) ? "Possible" : "Impossible")
#define pos(x) print((x) ? "possible" : "impossible")
const int INF = 1e16, MOD = 1e9 + 7, LIMIT = 100001, S_LIMIT = 101;
const int dx[] = {0, 0, 1, 0, -1, -1, 1, 1, -1}, dy[] = {0, -1, 0, 1, 0, -1, -1, 1, 1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int g[S_LIMIT][S_LIMIT] = {};
int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b){return a/gcd(a, b)*b;}
int modpw(int x, int n){return n < 2 ? x : modpw(x*x%MOD, n/2)*(n%2 ? x : 1)%MOD;}
int factorial(int a){return a < 2 ? 1 : factorial(a - 1)*a;}
int summation(int a){return a < 1 ? 0 : (a*a + a)/2;}
int combination(int n, int r){int res = 1; rep(i, 1, r + 1) res *= n--, res /= i; return res;}
int modcomb(int n, int r){return factorial(n)*modpw(factorial(r), MOD - 2)%MOD*modpw(factorial(n - r), MOD - 2)%MOD;}
mint factoriazation(int n){
    mint ans;
    rep(i, 2, sqrt(n) + 1) while(!(n%i)) ans[i]++, n /= i;
    if(n != 1) ans[n]++;
    return ans;
}
void warshall(int n){rep(i, n) rep(j, n) rep(k, n) chmin(g[j][k], g[j][i] + g[i][k]);}
struct UF{
    vint data;
    UF(int size): data(size, -1){}
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x != y){
            if(data[y] < data[x]) swap(x, y);
            data[x] += data[y], data[y] = x;
        }
        return x != y;
    }
    int root(int x){return data[x] < 0 ? x : data[x] = root(data[x]);}
    bool find(int x, int y){return root(x) == root(y);}
    int size(int x){return -data[root(x)];}
};
int a, b, c, k, n, m, x, y, z, ww, h, res = 0, cnt = 0, sum = 0, mx = -INF, mn = INF;
string s, t;
map<pint, int> memo;
int w[100],v[100];

int dp(int i, int j){
	pint p = mp(i, j);
	if(memo.count(p)){
        return memo[p];
    }
	int res;
	if(i == n){
        res = 0;
	}else if(j < w[i]){
        res = dp(i + 1, j);
	}else{
        res = max(dp(i + 1, j), dp(i + 1, j - w[i]) + v[i]);
    }
	return memo[p] = res;
}

signed main(){
    incant();
    in(n, ww);
    rep(i, n){
        in(w[i], v[i]);
	}
    out(dp(0, ww));
}
