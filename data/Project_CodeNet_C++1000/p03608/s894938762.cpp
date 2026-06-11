#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define INF (1ll<<60)
#define mod 1000000007
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll n,M,R;

void dijkstra(vector<vector<P>> &G,ll start,vector<ll> &dist,vector<ll> &prev){
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
            if(dist[next.first]>dist[now.second]+next.second){//最短になる場合
                dist[next.first]=dist[now.second]+next.second;//最短距離更新
                que.push(make_pair(dist[next.first],next.first));
            
                prev[next.first]=now.second;//now.secondを通って、nextに到着
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
    cin>>n>>M>>R;
    vector<ll> r(R);
    rep(i,R){
        cin>>r[i];
        r[i]--;
    }

    vector<vector<P>> G(n);
    rep(i,M){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;

        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    sort(r.begin(),r.end());//next_permutationで全探索したいが、昇順ソートしておかないと、途中からの順列になるので全探索不可
    vector<vector<ll>> MINdist(n,vector<ll>(n));//それぞれの頂点からの最短距離を格納
    for(ll i=0;i<R;i++){
        vector<ll> dist,prev;
        dijkstra(G,r[i],dist,prev);
        for(auto j:r){
            MINdist[r[i]][j]=dist[j];//i->jのmin
        }
    }


    ll ans=INF;
    do{
        ll sum=0;
        rep(i,R-1){
            sum+=MINdist[r[i]][r[i+1]];
        }
        chmin(ans,sum);
    }while(next_permutation(r.begin(),r.end()));

    cout<<ans<<endl;
    return 0;
}