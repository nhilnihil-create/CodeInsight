#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ull x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

const int MAX = 100010;
vll g[MAX];
bool used[MAX];
vll ans1;
vll ans2;
bool F;

template<class T>
void PrintVector(vector<T>& vec){
    int n = vec.size();
    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << vec[i]+1 << (i == n-1 ? "\n" : " ");
    }
}

void dfs(ll s){
    used[s] = true;
    if(F){
        ans1.emplace_back(s);
    }else{
        ans2.emplace_back(s);
    }
    for(auto&& e: g[s]){
        if(!used[e]){
            dfs(e);
            break;
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, m;
    cin >> n >> m;
    vll a(m), b(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].emplace_back(b[i]);
        g[b[i]].emplace_back(a[i]);
    }
    rep(i, n){
        if(SZ(g[i]) == 1){
            F = true;
            dfs(i);
            PrintVector(ans1);
            return 0;
        }
    }
    F = true;
    dfs(0);
    F = false;
    dfs(0);
    reverse(ALL(ans1));
    ans1.pop_back();
    for(auto&& e: ans2){
        ans1.emplace_back(e);
    }
    PrintVector(ans1);
    return 0;
}