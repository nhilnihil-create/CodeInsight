#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,v.size())i>>v[j];return i;}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

void dijkstra(vector<VP> g, ll start, Vec &dist, VV &root) {
    priority_queue<ll, vector<P>, function<bool(P, P)>> q([](P a, P b)->ll {
        return a.second > b.second;
    });
    dist[start] = 0;
    q.push(mp(start, 0));
    while (!q.empty()) {
        P now = q.top();
        q.pop();
        Each(nxt, g[now.fi]) {
            if(dist[nxt.fi]==now.se+nxt.se){
                root[nxt.fi].pb(now.fi);
            }
            if(chmin(dist[nxt.fi], now.se+nxt.se)) {
                q.push(mp(nxt.fi, dist[nxt.fi]));
                Vec x;
                x.pb(now.fi);
                root[nxt.fi] = x;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n,m;
    cin>>n>>m;
    vector<VP> g(n);
    map<pair<ll,ll>,ll> set;
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
        if(a<b){
            set[mp(a,b)]++;
        }else{
            set[mp(b,a)]++;
        }
    }

    rep(i,n){
        Vec dist(n,INF);
        VV par(n);
        dijkstra(g,i,dist,par);
        map<pair<ll,ll>,ll> rt;
        auto dfs = [&](auto dfs,ll v)->void{
            Each(nx, par[v]){
                if(rt[mp(v,nx)])continue;
                if(nx==-1)continue;
                rt[mp(v,nx)]++;
                if(nx<v){
                    set[mp(nx,v)]++;
                }else{
                    set[mp(v,nx)]++;
                }
                dfs(dfs,nx);
            }
        };
        rep(j,n){
            dfs(dfs,j);
        }
        //dbgmap(set);
    }
    ll ans=0;
    Each(p,set){
        if(p.se==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return  0;
}
