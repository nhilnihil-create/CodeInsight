#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;
const int MAX_V = 1e5;


struct edge {
	int to, cost;
};
// O(ElogV)
struct C {
	ll d[MAX_V];
	//bool used[MAX_V];
	int V;
	vector<edge> G[MAX_V];
	void dijkstra(int s) {
		fill(d, d + V, INF);
		d[s] = 0;
		priority_queue<P, vector<P>, greater<P> > q;
		q.push(make_pair(0, s)); // distance, index)

		while(!q.empty()) {
			P p = q.top();
			q.pop();
			int v = p.second;
			if(d[v] < p.first) continue;
			rep(i, 0, G[v].size()) {
				edge e = G[v][i];
				if(d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					q.push(P(d[e.to], e.to));
				}
			}
		}
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	C c1, c2;
	c1.V = c2.V = N;
	rep(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge e1, e2;
		e1.to = b;
		e1.cost = 1;
		e2.to = a;
		e2.cost = 1;

		c1.G[a].push_back(e1);
		c1.G[b].push_back(e2);

		c2.G[a].push_back(e1);
		c2.G[b].push_back(e2);
	}

	c1.dijkstra(0);
	c2.dijkstra(N - 1);

	int cnt1 = 0, cnt2 = 0;
	rep(i, 0, N) {
		if(c1.d[i] <= c2.d[i]) cnt1++;
		else if(c1.d[i] > c2.d[i]) cnt2++;
	}

	if(cnt1 > cnt2) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
}
