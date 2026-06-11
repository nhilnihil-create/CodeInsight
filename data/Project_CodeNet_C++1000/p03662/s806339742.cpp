#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define INF 1000000009
#define MAX_V 100000

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int previous[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    fill(previous,previous+V,-1);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                previous[e.to]=v;
            }
        }
    }
}

vector<int> get_path(int t){
    vector<int> path;
    for(;t!=-1;t=previous[t])path.push_back(t);
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    cin>>V;
    rep(i,V-1){
        int a,b;
        cin>>a>>b;
        --a;--b;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    dijkstra(0);
    auto gp=get_path(V-1);
    int reached[V];
    memset(reached,0,sizeof(reached));
    reached[gp[((int)gp.size()+1)/2]]=1;
    stack<int> st;
    st.push(0);
    reached[0]=1;
    int ctr=1;
    while(!st.empty()){
        int sttop=st.top();
        st.pop();
        for(auto au:G[sttop]){
            if(reached[au.to]==1)continue;
            reached[au.to]=1;
            ctr++;
            st.push(au.to);
        }
    }
    cout<<(ctr>V-ctr?"Fennec":"Snuke")<<endl;
}