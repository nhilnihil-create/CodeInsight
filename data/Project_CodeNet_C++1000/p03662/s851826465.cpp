#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)
#define pb push_back
#define INF 1000000007LL
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

typedef long long ll;
typedef pair<ll,ll> p;

ll dy[4]={-1,1,0,0};
ll dx[4]={0,0,1,-1};

vector<vector<bool> > canDraw;
vector<ll> used;
ll N;

#define MAX_V 100010
struct edge {ll to, cost;};
ll V;
vector<edge> G[MAX_V];
vector<ll> pre;
ll d[MAX_V];

void dijkstra(ll s){
    priority_queue<p,vector<p>, greater<p> > que;
    fill(d,d+V, INF);
    d[s]=0;
    que.push(p(0,s));
    while(!que.empty()){
        p pi = que.top(); que.pop();
        ll v = pi.second;
        if(d[v] < pi.first) continue;
        REP(i,G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                pre[e.to] = v;
                que.push(p(d[e.to],e.to));
            }
        }
    }
}

void dfn(int s) {
    for(auto x: G[s]) {
        if(used[x.to] == 0) {
            used[x.to] = 1;
            dfn(x.to);
        }
    }
}

void dsn(int s) {
    for(auto x: G[s]) {
        if(used[x.to] == 0) {
            used[x.to] = 2;
            dsn(x.to);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    V = N;
    pre.resize(N,0);
    REP(i, N-1) {
        ll a, b;
        cin >> a >> b;
        G[a-1].pb(edge{b-1, 1});
        G[b-1].pb(edge{a-1, 1});
    }
    dijkstra(0);
    vector<ll> ppath;
    set<ll> sn;
    set<ll> fn;
    used = vector<ll>(N);
    ll pr = N-1;
    ppath.pb(N-1);
    while(ppath[ppath.size()-1] != 0) {
        ppath.pb(pre[pr]);
        pr = pre[pr];
        // cout << pr << endl;
    }
    reverse(ppath.begin(), ppath.end());
    ll fnd = 1;
    ll snd = 2;
    ll cnt = 0;
    ll th = (ll)ppath.size()/2 + ppath.size()%2;
    ll fncnt = 0;
    ll sncnt = 0;
    for(auto x: ppath) {
        if (cnt+1 <= th) {
            used[x] = fnd;
        } else {
            used[x] = snd;
        }
        cnt++;
    }
    
    cnt = 0;
    for(auto x: used) {
        if(x == fnd) {
            dfn(cnt);
        } else if (x == snd) {
            dsn(cnt);
        }
        cnt++;
    }
    
    for(auto x: used) {
        if(x == fnd) {
            fncnt++;
        } else if (x == snd) {
            sncnt++;
        }
    }
    
    
//    cout << fncnt + sncnt << endl;
    
    if(sncnt < fncnt) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
    
    return 0;
}
