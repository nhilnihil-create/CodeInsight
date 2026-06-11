#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>> &pq) {return (ll)pq.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>, greater<T>> &pq) {return (ll)pq.size(); }
ll sz(string &s) {return (ll)s.size(); } 
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }
bool checkindex(ll i,ll n){ return (i < n && i >= 0); }

vector<P> vec;

struct edge{
    ll to,cost;  
};

void dijkstra(ll V,vector<vector<edge> > &G,vector<ll> &d,vector<ll> &d2,ll s){
    PQ que;
    fill(d.begin(),d.end(), LINF);
    fill(d2.begin(),d2.end(), -1);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;

        rep(i,0,G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
                d2[e.to] = v;
            }
        }
    }
}

int main(){
    ll n,m;
    cin >> n >> m;
    ll a,b,c;
    vector<vector<edge>> G(n);

    rep(i,0,m){
        cin >> a >> b >> c;
        a--;b--;
        edge e; e.cost = c; e.to = b;
        G[a].push_back(e);
        e.to = a;
        G[b].push_back(e);
    }

    rep(i,0,n){
        vector<ll> d(n),d2(n);
        dijkstra(n,G,d,d2,i);
        rep(j,i+1,n){
            ll temp = j,pre = -1;
            for(;temp != -1;temp = d2[temp]){
                if(pre != -1) vec.push_back(P((ll)min(pre,temp),(ll)max(pre,temp)));
                pre = temp;
            }
        }
    }

    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());

    cout << m - sz(vec) << endl;


    return 0;
}

