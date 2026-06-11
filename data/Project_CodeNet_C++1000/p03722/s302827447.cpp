#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

struct edge { int from, to , cost; };
edge es[2010];
ll d[1010];
int V, E;
void Bellman_Ford(int S)
{
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = es[j];
			if (d[e.from] != -INF && d[e.to] < d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
			}
		}
	}
}

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> es[i].from >> es[i].to >> es[i].cost;
		es[i].from--; es[i].to--;
	}
	ll ans;
	for (int i = 0; i < V; i++) d[i] = -INF;
	d[0] = 0;
	Bellman_Ford(0);
	ans = d[V - 1];
	Bellman_Ford(0);
	if (ans != d[V - 1])cout << "inf" << endl;
	else cout << ans << endl;
}
