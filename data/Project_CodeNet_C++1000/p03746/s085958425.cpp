#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cout << a[i] << " "; cout << "\n"; }
template<class T> void verr(const vector<T>& v){ for(auto& a : v) cout << a << " "; cout << "\n"; }
ll dbgt = 1; void err() { cout << "passed " << dbgt++ << "\n"; }
template<class H, class... T> void err(H&& h,T&&... t){ cout<< h << (sizeof...(t)?" ":"\n"); if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
struct UnionFind {
private:
    vector<int> par;
    vector<int> count;
    vector<int> rank;
public:
    UnionFind(int N) {
        count.assign(N, 1);
        rank.assign(N, 0);
        par.assign(N, 0);
        rep(i, N) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            par[x] = root(par[x]);
            return par[x];
        }
    }

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y])
            swap(x, y);
        else if (rank[x] == rank[y])
            rank[y]++;
        par[y] = x;
        count[x] += count[y];
        return;
    }

    int size(int x) {
        return count[root(x)];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};
using UF = struct UnionFind;

int main() {
    init();
    ll N,M;
    cin >> N >> M;
    vvc<ll> G(N);
    vl cnt(N);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--, b--;
        G[a].eb(b), G[b].eb(a);
        cnt[a]++, cnt[b]++;
    }

    UF uf(N);
    ll start = min_element(all(cnt)) - cnt.begin();

    deque<ll> dq;
    queue<ll> q;
    q.emplace(start);
    ll now = start;
    while(!q.empty()){
        now = q.front(), q.pop();
        dq.eb(now);
        uf.unite(start, now);
        for(auto& to:G[now]){
            if (uf.issame(now, to)) continue;
            q.emplace(to);
            break;
        }
    }

    q.emplace(start), now = start;
    while(!q.empty()){
        now = q.front(), q.pop();
        if (now != start) dq.emplace_front(now);
        uf.unite(start, now);
        for(auto& to:G[now]){
            if (uf.issame(now, to)) continue;
            q.emplace(to);
            break;
        }
    }

    cout << dq.size() << endl;
    while(!dq.empty()){
        cout << dq.front()+1 << " ";
        dq.pop_front();
    }
    cout << endl;
}