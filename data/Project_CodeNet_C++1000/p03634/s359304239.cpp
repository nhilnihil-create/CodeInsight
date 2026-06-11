#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

struct edge{
	ll to,cost;
};
typedef pair<int,int> P; //firstは最短距離、secondは頂点の番号

int V; //頂点数
vector<edge> G[100010];
ll d[100010]; //頂点sからの最短距離
int previ[100010];

void dijkstra(int s) {
	//greater<P>を指定することでfirstが小さい順に取り出せる
	priority_queue<P,vector<P>,greater<P>> que;
	fill(d,d + V,INF);
	fill(previ,previ + V,-1);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) {
			continue;
		}
		for(int i = 0;i < G[v].size();i++) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				previ[e.to] = v;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

vector<int> get_path(int t) {
	vector<int> path;
	while(t != -1) {
		path.push_back(t);
		t = previ[t];
	}
	reverse(path.begin(),path.end());
	return path;
}

int main() {
    cin >> V;
    for(int i = 0;i < V - 1;i++) {
        ll A,B,C;
        cin >> A >> B >> C;
        G[A - 1].push_back(edge{B - 1,C});
        G[B - 1].push_back(edge{A - 1,C});
    }
    int Q,K;
    cin >> Q >> K;
    K--;
    dijkstra(K);
    for(int i = 0;i < Q;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        cout << d[A] + d[B] << endl;
    }
}