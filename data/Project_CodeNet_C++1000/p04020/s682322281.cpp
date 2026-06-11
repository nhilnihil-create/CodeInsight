#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    ll icnt,bcnt;
    icnt = bcnt = 0;
    //前から
    int num = 0;
    rep(i,N-1){
        int m;
        m = (a[i] - num)/2;
        icnt += m;
        num += m*2;
        icnt += min(a[i]-num,a[i+1]);
        num = min(a[i]-num,a[i+1]);
    }
    icnt += (a[N-1] - num) / 2;
    //後ろから
    num = 0;
    rep(i,N-1){
        int m;
        m = (a[N-1-i]- num)/2;
        bcnt += m;
        num += m * 2;
        bcnt += min(a[N-1-i] -num,a[N-2-i]);
        num = min(a[N-1-i] -num,a[N-2-i]);
    }
    bcnt += (a[0] - num) / 2;
    cout << max(bcnt,icnt) << endl;
}