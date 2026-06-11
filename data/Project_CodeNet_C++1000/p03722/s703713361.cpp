#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int MAX_N = 1005;
const long long INF = 1LL<<60;

int v, e;
vector<tuple<int, int, int>> es;
vector<long long> d;

vvi to(MAX_N), ot(MAX_N);
bool seen_1[MAX_N], seen_2[MAX_N], seen[MAX_N];

void dfs(int v) {
    if (seen_1[v]) return;
    seen_1[v] = true;
    for (int u : to[v]) {
        dfs(u);
    }
}

void rdfs(int v) {
    if (seen_2[v]) return;
    seen_2[v] = true;
    for (int u : ot[v]) {
        rdfs(u);
    }
}

bool bellmanford(int s) {
    d = vector<long long>(v, INF);
    d[s] = 0;
    for (int t = 0; t < v; ++t){
        bool update = false;
        for (int i = 0; i < e; ++i) {
            int from, to;
            long long cost;
            tie(from, to, cost) = es[i];
            if (!seen[to] || !seen[from]) continue;
            if (d[from] != INF && d[to] > d[from] + cost) {
                update = true;
                d[to] = d[from] + cost;
            }
        }
        if (!update) break;
        if (t == v-1) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> v >> e;
    rep(i, e) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        to[a].pb(b);
        ot[b].pb(a);
        es.eb(a, b, -c);
    }
    dfs(0);
    rdfs(v-1);
    rep(i, v) seen[i] = seen_1[i] && seen_2[i];
    if (bellmanford(0)) cout << "inf" << endl;
    else cout << -d[v-1] << endl;
}


// #include <bits/stdc++.h>
// #define _GLIBCXX_DEBUG
// #define rep(i,n) for(int i = 0; i < (int)(n); i++)
// #define fi first
// #define se second
// #define pb push_back
// #define eb emplace_back
// #define sz(x) (int)(x).size()
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// using namespace std;
// using ll = long long;
// using P = pair<int, int>;
// using vi = vector<int>;
// using vc = vector<char>;
// using vb = vector<bool>;
// using vs = vector<string>;
// using vll = vector<long long>;
// using vp = vector<pair<int, int>>;
// using vvi = vector<vector<int>>;
// using vvc = vector<vector<char>>;
// using vvll = vector<vector<long long>>;
// template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
// template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

// const ll INF = 1LL<<60;
// const int MAX_N = 1005;

// vvi to(MAX_N), ot(MAX_N);
// vector<tuple<int, int, int>> es;
// bool seen_1[MAX_N], seen_2[MAX_N], seen[MAX_N];
// ll d[MAX_N];

// void dfs(int v) {
//     if (seen_1[v]) return;
//     seen_1[v] = true;
//     for (int u : to[v]) {
//         dfs(u);
//     }
// }

// void rdfs(int v) {
//     if (seen_2[v]) return;
//     seen_2[v] = true;
//     for (int u : ot[v]) {
//         rdfs(u);
//     }
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     rep(i, m) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--; b--;
//         to[a].pb(b);
//         ot[b].pb(a);
//         es.eb(a, b, -c);
//     }
//     dfs(0);
//     rdfs(n-1);
//     rep(i, n) seen[i] = seen_1[i] && seen_2[i];
//     rep(i, n) d[i] = INF;
//     d[0] = 0;
//     bool neg = false;
//     for (int i = 0; ; ++i) {
//         bool update = false;
//         rep(j, m) {
//             int from, to; ll cost;
//             tie(from, to, cost) = es[j];
//             if (!seen[from] || !seen[to]) continue;
//             if (d[from] != INF && chmin(d[to], d[from] + cost)) update = true;
//         }
//         if (!update) break;
//         if (i == n-1) { neg = true; break;} 
//     }
//     if (neg) cout << "inf" << endl;
//     else cout << -d[n-1] << endl;
// }
