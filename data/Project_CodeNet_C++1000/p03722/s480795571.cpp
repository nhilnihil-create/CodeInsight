#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;
struct edge{ll from, to, cost;};

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int V,E;
vector<edge> es(2000);
vector<ll> d(1000,IINF);
vector<bool> used(1000,false);

bool BellmanFord(int s){
    d[s]=0;
    int count=0;
    while (true){
        bool update=true;
        rep(i,E){
            edge e=es[i];
            if (d[e.from]!=IINF&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=false;
                if (count==V-1&&used[e.to]){
                    return true;
                }
            }
        }
        if (update){
            return false;
        }
        count++;
        if (count==V){
            return false;
        }
    }
}

vector<vector<int>> G(1000);
void reachgoal(int g){
    used[g]=true;
    queue<int> que;
    que.push(g);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for (auto nv:G[v]){
            if (used[nv]){
                continue;
            }
            used[nv]=true;
            que.push(nv);
        }
    }
}

int main(){
    cin >> V >> E;
    rep(i,E){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--,b--;
        es[i]=edge{a,b,-c};
        G[b].push_back(a);
    }
    reachgoal(V-1);
    if (BellmanFord(0)){
        cout << "inf" << endl;
        return 0;
    }
    cout << -d[V-1] << endl;
}