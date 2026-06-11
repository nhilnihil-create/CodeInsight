#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

/*方針*/
/*
➀dijkstra法で最短経路を見つけて(経路復元)、通った辺に判定をつける
➁通っていない辺の数を数える
*/
ll n,m;

void dijkstra(Graph &G,map<P,ll> &bet,ll start,vector<ll> &dist,vector<ll> &prev){
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,start});
    
    prev.assign(n,-1);
    dist.assign(n,INF);
    dist[start]=0;

    while(que.size()){
        P now=que.top();
        que.pop();
        if(dist[now.second]<now.first) continue;//今、最短距離でないなら無視する

        for(auto next:G[now.second]){
            if(dist[next]>dist[now.second]+bet[make_pair(now.second,next)]){//最短になる場合
                dist[next]=dist[now.second]+bet[make_pair(now.second,next)];//最短距離更新
                que.push(make_pair(dist[next],next));
            
                prev[next]=now.second;//now.secondを通って、nextに到着
            }
        }
    }
}

vector<ll> get_path(vector<ll> &prev,int goal){//経路復元
    vector<ll> path;
    for (ll cur=goal;cur!=-1;cur=prev[cur]){
        path.push_back(cur);
    }
    reverse(path.begin(),path.end());//逆順なのでひっくり返す
    return path;
}

int main(){
    cin>>n>>m;
    Graph G(n);
    map<P,ll> bet;//2点間距離
    vector<P> stay;//pairを保存

    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        bet[make_pair(a,b)]=c;//a-b間距離
        bet[make_pair(b,a)]=c;

        stay.push_back(make_pair(a,b));//頂点を保存
        stay.push_back(make_pair(b,a));
    }

    map<P,bool> visit;//ある辺について訪れたかどうかの判定
    rep(i,stay.size()){
        visit[stay[i]]=false;//初期化
    }

    rep(i,n){
        rep(j,n){
            if(i==j) continue;
            vector<ll> dist,prev;

            dijkstra(G,bet,i,dist,prev);
            vector<ll> path=get_path(prev,j);

            rep(k,path.size()-1){
                visit[make_pair(path[k],path[k+1])]=true;//訪れた辺はtrue
                visit[make_pair(path[k+1],path[k])]=true;
            }
        }
    }

    ll ans=2*m;
    rep(i,stay.size()){
        if(visit[stay[i]]){
            ans--;//訪れていたら、-1
        }
    }

    cout<<ans/2<<endl;//(a,b),(b,a)のように二つずつ数えているから2で割る

    return 0;
}