#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

bool used[100][100];
bool fin[100][100];

pll d[100][100];

void dfs(ll s,ll t){
    if(fin[s][t] || fin[t][s]) return ;
    if(d[s][t].fi==-1){
        used[s][t]=true;
        used[t][s]=true;
        fin[s][t]=true;
        fin[t][s]=true;
        return ;
    }
    fin[s][t]=true;
    fin[t][s]=true;
    dfs(s,d[s][t].fi);
    dfs(d[s][t].fi,t);
    
    return ;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<pll> edge(m);
    rep(i,n){
        rep(j,n){
            d[i][j]=make_pair(-1,INF);
        }
    }
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b]=make_pair(-1,c);
        d[b][a]=make_pair(-1,c);
        edge[i]=make_pair(a,b);
    }
    
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(d[i][j].se>d[i][k].se+d[k][j].se){
                    d[i][j]=make_pair(k,d[i][k].se+d[k][j].se);
                }
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(i==j) continue;
            dfs(i,j);
        }
    }
    ll ans=m;
    rep(i,m){
        if(used[edge[i].fi][edge[i].se]) ans--;
    }
    cout << ans << endl;
    return 0;
}