#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e14;
const int ZERO = 0;
const double PI = 3.14159265359;
typedef pair<int,int> P;

//頂点fromから頂点toへのコストcostの辺
struct edge{
	int from,to,cost;
};

edge es[100010]; //辺
int d[100010]; //最短距離
int N,M; //頂点数、辺数
bool negative[100010];

//ｓ番目の頂点から各頂点への最短距離を求める
int shortest_path(int s) {
	for(int i = 0;i < N;i++) {
		d[i] = INF;
	}
	d[s] = 0;
	for(int j = 0;j < N - 1;j++) {
		bool update = false;
		for(int i = 0;i < M;i++) {
			edge e = es[i];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(update == false) {
			break;
		}
	}
    int ans = d[N - 1];
    for(int i = 0;i < N;i++) {
        negative[i] = false;
    }
    for(int i = 0;i < N;i++) {
        bool update = false;
		for(int i = 0;i < M;i++) {
			edge e = es[i];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
				update = true;
			}
		}
		if(update == false) {
			break;
		}
    }
    if(negative[N - 1] == true) {
        return INF;
    }
    else {
        return -ans;
    }
}

signed main() {
    cin >> N >> M;
    for(int i = 0;i < M;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        es[i] = edge{A - 1,B - 1,-C};
    }
    if(shortest_path(0) == INF) {
        cout << "inf" << endl;
    }
    else {
        cout << shortest_path(0) << endl;
    }
}