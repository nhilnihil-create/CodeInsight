#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define rep(i,x) for(int i = 0;i<x;i++)
#define REP(i,x) for(ll i = 1;i<=x;i++)
#define mp make_pair
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll inf = 2147483647;
const ll INF = 1LL << 60;
const dou pi = 3.14159265358;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
template<class T> inline bool change(T a,T b){if(a > b){swap(a,b);return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}

//素数判定O(sqrt(N))
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
const ll cmax = 1000000;
ll fac[cmax], finv[cmax], inv[cmax];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < cmax; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll nCk(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//nのm乗をMODで割ったあまりO(logm)
ll modpow(ll n,ll m,ll MOD){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}
ll mypow(ll n,ll m){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n);
        m >>= 1;
        n *= n;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,M;
    cin >> N >> M;
    struct edge{ll from,to,cost;};
    vector<edge> es(M);
    rep(i,M){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;es[i].to--;es[i].cost = -es[i].cost;
    }
    vector<ll> dist(N,INF);
    dist[0] = 0;
    ll ans1 = 0,ans2 = 0;
    rep(i,N + 2){
    //vecout(dist);
        rep(j,M){
            if(dist[es[j].from] == INF)continue;
            dist[es[j].to] = min(dist[es[j].from] + es[j].cost,dist[es[j].to]);
        }
        if(i == N - 1)ans1 = dist[N - 1];
        if(i == N + 1)ans2 = dist[N - 1];
    }
    //vecout(dist);
    if(ans1 == ans2){
        cout << -ans1 << "\n";
    }
    else{
        cout << "inf\n";
    }
}