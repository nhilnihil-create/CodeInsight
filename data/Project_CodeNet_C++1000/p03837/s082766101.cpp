#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> P;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};
int N,M;
vector<vector<pii> > G;
vector<vector<bool> > used;
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    vector<int> d(N,INF);
    d[s]=0;
    que.push(P(0,pii(s,-1)));
    while(!que.empty()){
        P p=que.top();que.pop();
        int md=p.first,u=p.second.first,t=p.second.second;
        if(md>d[u]) continue;
        if(t!=-1) used[t][u]=used[u][t]=true;
        for(auto e:G[u]){
            int v=e.first,c=e.second;
            if(d[v]>d[u]+c){
                d[v]=d[u]+c;
                que.push(P(d[v],pii(v,u)));
            }
        }
    }
}
int main(){
    cin>>N>>M;
    G=vector<vector<pii> >(N);
    used=vector<vector<bool> >(N,vector<bool>(N,true));
    for(int i=0;i<M;++i){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(pii(b,c));
        G[b].push_back(pii(a,c));
        used[a][b]=used[b][a]=false;
    }
    for(int i=0;i<N;++i){
        dijkstra(i);
    }
    int ans=0;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            if(!used[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

