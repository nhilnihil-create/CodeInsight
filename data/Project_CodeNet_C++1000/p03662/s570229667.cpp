//     _/    _/  _/                        _/                
//    _/    _/      _/_/_/      _/_/_/  _/_/_/_/    _/_/_/   
//   _/_/_/_/  _/  _/    _/  _/    _/    _/      _/    _/    
//  _/    _/  _/  _/    _/  _/    _/    _/      _/    _/     
// _/    _/  _/  _/    _/    _/_/_/      _/_/    _/_/_/ 
// C++ Conpetitive Programming Template 
// Ver 1.1 (codename: Hinata)
// Last Modified : 2019-05-28
// Created       : 2019-05-25
// Auther        : shirataki3
#include <bits/stdc++.h>
using namespace std;
// typename alias
template <class T> using vec = vector<T>;
template <class T, class U> using vep = vec<pair<T,U> >;
template <class T> using PQ = priority_queue<T>;
using ll = long long;
using vll = vec<ll>;
using pll = pair<ll, ll>;
using vpll = vec<pll>;
using str = string;
// あくまのちから
//#define int ll

// const
static const long long INF = 1LL<<59;
static const long long MOD = (ll)1e9+7;
static const double PI = 3.14159265358979323846;

// accelerate stdin, stdout
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// repeat macro
#define FOR(i, a, b) for(ll (i)=(a);(i)<=(b);i++)
#define rFOR(i, a, b) for(ll (i)=(b);(i)>=(a);i--)
#define REP(i, n) for(ll i=0;i<n;i++)
// vector macro
#define WHOLE(v) (v).begin(), (v).end()
#define ASC(v) sort(WHOLE(v))
#define DESC(v) sort((v).rbegin(), (v).rend())
#define INV(v) reverse(WHOLE(v))
#define FOLDL(src, dst, lambda) partial_sum(WHOLE(src), (dst).begin(), lambda)
#define FOLDR(src, dst, lambda) INV(src);partial_sum(WHOLE(src), (dst).begin(), lambda);INV(dst)
#define CUMSUML(src, dst) FOLDL(src, dst, [](auto a, auto b) {return a+b;})
#define CUMSUMR(src, dst) FOLDR(src, dst, [](auto a, auto b) {return a+b;})
#define ACCUM(v, d0, lambda) accumulate(WHOLE(v), d0, lambda)
#define SUM(v, d0) ACCUM(v, d0, [](auto a, auto b) {return a+b;})
#define ERASE(v, i) v.erase(v.begin() + i)
#define UNIQ(v) ASC(v);v.erase(unique(v.begin(), v.end()), v.end())

// io helper
template <typename T>void debug(T t) {cerr << t << endl;}
template <typename T, typename ...Args>void debug(T t, Args ...args) {cerr << t << " ";debug(args...);}
template <typename T>void out(T t) {cout << t << endl;}
template <typename T, typename ...Args>void out(T t, Args ...args) {cout << t << " ";out(args...);}
template <typename T>istream& operator>>(istream &is, vec<T> &v) {for(auto &a:v) is >> a; return is;}
template <typename T>ostream& operator<<(ostream &os, vec<T> &v) {os << "[";REP(i, v.size() - 1) os << v[i] <<", "; os << v[v.size()-1]<<"]";return os;}
template <typename T, typename U>ostream& operator<<(ostream &os, pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>ostream& operator<<(ostream &os, map<T, U> &mp) {os << "{ ";for(auto &p:mp) os << p.first << ": " << p.second << ", "; os << "}";return os;}

vec<vll> adj;
vll color, dist, pre;
ll N;

void dijkstra(ll s) {
    dist.assign(N, INF);
    pre.assign(N, -1);
    dist[s] = 0;
    priority_queue<pll, vpll, greater<pll> > q;
    q.push({0, s});
    while(!q.empty()) {
        pll p = q.top();q.pop();
        int v = p.second;
        if(dist[v] < p.first) {
            continue;
        }
        for(auto &to:adj[v]) {
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                pre[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}

vll minimum_path(ll t) {
    vll res;
    for(; t != -1; t = pre[t]) {
        res.push_back(t);
    }
    INV(res);
    return res;
}

void solve() {
    cin >> N;
    adj.resize(N);
    color.assign(N, -1);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dijkstra(0);
    vll path = minimum_path(N - 1);
    color[0] = 0;     // Fennec
    color[N - 1] = 1; // Snuke
    FOR(i, 0, (path.size()-1) / 2) {
        color[path[i]] = 0;
    }
    rFOR(i, (path.size()-1)/ 2 + 1, path.size() - 1) {
        color[path[i]] = 1;
    }
    ll num0 = 1;
    queue<ll> q;
    q.push(0);
    color[0] = 2;
    while(!q.empty()) {
        ll f = q.front();q.pop();
        for(auto &to:adj[f]) {
            if(color[to] == -1 || color[to] == 0) {
                num0++;
                color[to] = 2;
                q.push(to);
            }
        }
    }
    ll num1 = 1;
    queue<ll> q2;
    q2.push(N-1);
    color[N-1] = 3;
    while(!q2.empty()) {
        ll f = q2.front();q2.pop();
        for(auto &to:adj[f]) {
            if(color[to] == -1 || color[to] == 1) {
                num1++;
                color[to] = 3;
                q2.push(to);
            }
        }
    }
    if(num0 > num1) out("Fennec");
    else out("Snuke");
}

signed main() {
    fast_io;
    cout << setprecision(20) << fixed;
    solve();
    return 0;
}