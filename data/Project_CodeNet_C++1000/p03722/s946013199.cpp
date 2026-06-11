#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define countof(array) (sizeof(array) / sizeof(array[0]))
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,n,s) for(int i = s; i < (n); ++i)
#define rsrep(i,n,s) for(int i = (n)-1; i >= s; --i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define aall(a) (a), (a)+countof(a)//for array sorting
#define raall(a) (a), (a)+countof(a), greater<>()
#define show(x) cout<<#x<<" = "<<x<<endl;
#define vfind(v, a) find(all(v), a) != v.end()
#define yn(f) { if (f) puts("YES"); else puts("NO"); }
#define yns(f) { if (f) puts("Yes"); else puts("No"); }
#define show_ary(...) { cout<<#__VA_ARGS__<<" = "; for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define show_pair(...) cout<<#__VA_ARGS__<<" = "<<endl; for (const auto& x : (__VA_ARGS__)) { cout<<"  "<<x.fi<<" : "<<x.se<<endl; }
#define out_ary(...) { for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define argmax(v) distance((v).begin(), max_element(all(v)))
#define argmin(v) distance((v).begin(), min_element(all(v)))
#define vmax(v) *max_element(all(v))
#define vmin(v) *min_element(all(v))
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<P> vpair;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<vstr> vvstr;
typedef vector<vbool> vvbool;
const ll LINF = 2000000000000000000ll;
const int INF = 1000000100;
const ll MOD = 1e9+7;

vint to[1005], rto[1005];
vbool from_1(1005, false), to_n(1005, false);

struct edge {
    int to;
    int from;
    ll cost;
};
 
void dfs(int v) {
    if (from_1[v]) return;
    from_1[v] = true;
    for (int u : to[v]) dfs(u);
}
 
void rdfs(int v) {
    if (to_n[v]) return;
    to_n[v] = true;
    for (int u : rto[v]) rdfs(u);
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    rep(i, m) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
        e[i].from--;
        e[i].to--;
        e[i].cost *= -1;
        to[e[i].from].push_back(e[i].to);
        rto[e[i].to].push_back(e[i].from);
    }
 
    dfs(0);
    rdfs(n-1);
    vbool ok(n);
    rep(i, n) {
        ok[i] = from_1[i] & to_n[i];
    }
 
    vll v(n, LINF);
    v[0] = 0;
    rep(i, n) {
        bool update = false;
        rep(j, m) {
            if (ok[e[j].from] == false || ok[e[j].to] == false) continue;
            if (v[e[j].to] > v[e[j].from] + e[j].cost) {
                v[e[j].to] = v[e[j].from] + e[j].cost;
                update = true;
            }
        }
        if (i == n-1 && update) {
            puts("inf");
            return 0;
        }
    }
    ll ans = v[n-1] * -1;
    cout << ans << endl;
    return 0;
}