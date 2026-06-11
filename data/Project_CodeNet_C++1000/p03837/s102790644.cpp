//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<pii>> g;
set<pii> e;
vector<int> dis;
int n;

void dijkstra(int s){

    dis.clear();
    dis.resize(n + 1, MAX);
    dis[s] = 0;

    std::priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push(mp(0, s));
    while(!pq.empty()){
        int now = pq.top().S, d = pq.top().F;
        pq.pop();
        if(d != dis[now]) continue;
        for(pii i : g[now]){
            if(d + i.S < dis[i.F]){
                dis[i.F] = d + i.S;
                pq.push(mp(d + i.S, i.F));
            }
        }
    }

}

int main(){
    StarBurstStream

    int m;
    cin >> n >> m;

    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].eb(mp(v, c));
        g[v].eb(mp(u, c));
    }

    for(int i = 1; i <= n; i++){

        dijkstra(i);

        for(int u = 1; u <= n; u++){
            for(pii v : g[u]){
                if(dis[v.F] == dis[u] + v.S) e.insert(mp(min(u, v.F), max(u, v.F)));
            }
        }

    }

    cout << m - e.size() << "\n";

    return 0;
}