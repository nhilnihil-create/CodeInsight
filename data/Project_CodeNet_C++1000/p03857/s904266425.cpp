#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define SZ(v)       (ll)(v).size()
#define ALL(v)      (v).begin(),(v).end()
#define UNIQ(v)     sort(ALL(v));(v).erase(unique(ALL(v)),(v).end())
#define IN(x,l,r)   ((l)<=(x)&&(x)<=(r))
#define BIT(n)      (1LL<<(n))
#define PQ(T)       priority_queue<T,vector<T>,greater<T>>
#define SHOW(x)     cout<<#x<<" = "<<x<<endl

template<typename T>string join(const vector<T>& v, string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(d.length());}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v)
{if(SZ(v))s<<join(v,", ");return s;}

const ll inf = 1e15;
const ll mod = 1e9+7;
const double eps = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

struct union_find_tree {
    vector<ll> par;
    vector<ll> rnk;
    union_find_tree() = default;
    explicit union_find_tree(size_t n) : par(n+1), rnk(n+1, 0) {}
    
    void init(ll n) {
        REP(i, n+1) par[i] = i;
    }
    
    ll find(ll x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rnk[x] < rnk[y]) par[x] = y;
        else {
            par[y] = x;
            if (rnk[x] == rnk[y]) rnk[x]++;
        }
    }
    
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

int main() {
    ll N, K, L; cin >> N >> K >> L;
    
    union_find_tree uf1(N);
    uf1.init(N);
    REP(i, K) {
        ll p, q; cin >> p >> q;
        uf1.unite(p, q);
    }
    
    union_find_tree uf2(N);
    uf2.init(N);
    REP(i, L) {
        ll r, s; cin >> r >> s;
        uf2.unite(r, s);
    }
    
    map<pair<ll, ll>, ll> cnt;
    REP(i, N) cnt[make_pair(uf1.find(i+1), uf2.find(i+1))]++;
    
    REP(i, N) cout << cnt[make_pair(uf1.find(i+1), uf2.find(i+1))] << " ";
    cout << endl;
    
    return 0;
}
