#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define rep(i,x) for(ll i = 0;i<x;i++)
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
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool change(T& a,U& b){if(a > b){swap(a,b);return 1;}return 0;}
template<class T>
T gcd(T a,T b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
template<class T>
T lcm(T a,T b){
    return a / gcd(a,b) * b;
}

//素数判定O(sqrt(N))
template<class T>
inline bool isp(T n){
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
vector<ll> fac(cmax),finv(cmax),inv(cmax);

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
    if(fac[0] == 0)COMinit();
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
//ここから
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //0.辺の定義
    struct edge{ll from,to,cost;};
    //1,入力
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    vector<edge> es(M);
    rep(i,M){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;es[i].to--;
        dist[es[i].from][es[i].to] = es[i].cost;
        dist[es[i].to][es[i].from] = es[i].cost;
    }
    rep(i,N){
        dist[i][i] = 0;
    }
    //2.ワーシャルフロイドでdistを埋める
    rep(i,N){
        rep(j,N){
            rep(k,N){
                chmin(dist[j][k],dist[j][i] + dist[i][k]);
            }
        }
    }
    //3.全ての辺を走査して答えを数え上げる
    ll ans = 0;
    rep(e,M){
        bool ok = 1,go = 0;
        rep(i,N){
            rep(j,N){
                if(dist[i][j] == dist[i][es[e].from] + es[e].cost + dist[es[e].to][j]){//
                    ok = 0;
                    go = 1;
                    break;
                }
            }
            if(go)break;
        }
        if(ok)ans++;
    }
    //4.出力
    cout << ans << "\n";
    //デバッグ
    /*rep(i,N){
        rep(j,N){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }*/
}