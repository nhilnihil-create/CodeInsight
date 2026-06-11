#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1000000000000000000;

const ll max_V=1000;//大きすぎ注意

struct edge{ll to,cost;};

ll N;//頂点数
ll M;
ll cst[max_V][max_V];
vector<edge> G[max_V];
//bool used[max_V];
//ll d[max_V];//頂点sからの最短距離

//ll pr[max_V];

void dijkstra(ll s,V<ll> &d,V<ll> &pr){
    priority_queue<P,vector<P>,greater<P>> que;
    // fill(d,d+N,INF);
    d[s]=0;
    que.push(P(0,s));//pair...first->最短距離、second->頂点

    while(!que.empty()){
        P p=que.top();que.pop();
        ll v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
                pr[e.to]=v;
            }
        }
    }
}

void dijkstra_restore(ll s,V<ll> &d,V<ll> &pr,V<bool> &used){
    // fill(d,d+N,INF);
    // fill(used,used+N,0);
    // fill(pr,pr+N,-1);
    d[s]=0;

    while(true){
        ll v=-1;
        for(int u=0;u<N;u++){
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        }

        if(v==-1) break;
        used[v]=1;

        for(int u=0;u<N;u++){
            if(d[u]>d[v]+cst[v][u]){
                d[u]=d[v]+cst[v][u];
                pr[u]=v;
            }
        }
    }
}

//頂点tへの最短路
vector<ll> get_path(ll t,V<ll> pr){
    vector<ll> path;
    for(;t!=-1;t=pr[t]) path.push_back(t);//tがsになるまでprev[t]をたどっていく
    reverse(all(path));
    return path;
}

signed main(){
    cin>>N>>M;
    set<ll> st;
    map<P,ll> mp;
    rep(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edge A,B;
        A.to=b;A.cost=c;
        B.to=a;B.cost=c;
        G[a].push_back(A);
        G[b].push_back(B);
        //cst[a][b]=cst[b][a]=c;
        mp[P(a,b)]=mp[P(b,a)]=i;
    }
    for(ll i=0;i<N-1;i++){
        for(ll j=i+1;j<N;j++){
            //if(i==j) continue;
            V<ll> dist(N,INF),pr(N,-1);
            V<bool> used(N,0);
            dijkstra(i,dist,pr);
            V<ll> path=get_path(j,pr);
            ll m=path.size();
            for(int k=0;k<m-1;k++){
                ll v=mp[P(path[k],path[k+1])];
                st.insert(v);
            }
        }
    }
    cout<<M-st.size()<<endl;
}