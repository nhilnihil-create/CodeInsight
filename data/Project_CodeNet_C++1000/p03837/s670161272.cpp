#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct edge{
    ll to,cost;
};
V<V<edge>> graph;
V<V<bool>> used;
V<ll> d1;
int n,m;
void dijkstra(ll s){
    d1.resize(n);
    for(int i=0;i<n;i++)d1[i]=inf;//訪れていない頂点をinfで初期化
    d1[s]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,s));//始点を０で置く
    while(!q.empty()){
        P a=q.top();
        q.pop();
        if(d1[a.se]<a.fi)continue;
        for(int i=0;i<graph[a.se].size();i++){
            edge e=graph[a.se][i];
            if(d1[e.to]>d1[a.se]+e.cost){
                d1[e.to]=d1[a.se]+e.cost;//訪れていないorより低いコストの経路を発見した時、値を更新
                q.push(P(d1[e.to],e.to));//コストの低いところ優先のbfs
            }
        }
    }
     q.push(P(0,s));
    while(!q.empty()){//経路復元
        P a=q.top();
        q.pop();
        if(d1[a.se]<a.fi)continue;
        for(int i=0;i<graph[a.se].size();i++){
            edge e=graph[a.se][i];
            if(d1[e.to]==d1[a.se]+e.cost){
                used[a.se][e.to]=false;
                used[e.to][a.se]=false;
                q.push(P(d1[e.to],e.to));
            }
        }
    }
    return;
}
int main(){
cin>>n>>m;
used.assign(n,V<bool>(n,false));
graph.resize(n);
for(int i=0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    graph[a].push_back(edge{b,c});
    graph[b].push_back(edge{a,c});
    used[a][b]=true;
    used[b][a]=true;
}
int ans=0;
for(int i=0;i<n;i++)dijkstra(i);
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++)if(used[i][j])ans++;
}
cout<<ans<<endl;
}