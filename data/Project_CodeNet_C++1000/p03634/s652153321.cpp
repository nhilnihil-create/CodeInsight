#include<bits/stdc++.h>
using namespace std;

struct edge {
    long long to;
    long long cost;
};

typedef pair<long long, long long> P;  // first: 最短距離, second: 頂点番号

int n;long long d[1000000];
vector<vector<edge>> G; // 隣接リスト表現

void dijkstra(int s) {
    fill(d, d + n, 1e18);
    d[s] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main(){
	cin>>n;
	G.resize(n);
	for(int i=0;i<n-1;++i){
		int a,b;long long t;
		cin>>a>>b>>t;
		a--;b--;
		G[a].push_back(edge{b,t});
		G[b].push_back(edge{a,t});
	}
    int q,k;cin>>q>>k;
    k--;
    dijkstra(k);
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<d[x]+d[y]<<endl;
    }
}
