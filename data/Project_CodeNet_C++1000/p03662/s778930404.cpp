#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
const ll MAX_10p5 = 100000;
const ll MAX_10p9 = 1000000000;
const ll MAX_10p18 = 1000000000000000000;
struct edge {
	ll to, cost;
	bool operator<(const edge& right) const {
		return cost == right.cost ? to < right.to : cost < right.cost;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

ll N, sum[2];
ll costs[2][MAX_10p5 + 10];
bool visited[2][MAX_10p5 + 10];
vector<edge> nodes[MAX_10p5 + 10];

void dfs(ll color, ll node, ll cost) {
	if (visited[color][node]) return;
	visited[color][node] = true;
	costs[color][node] = cost;
	repi(i, 0, nodes[node].size()) dfs(color, nodes[node][i].to, cost + 1);
	return;
}

int main() {
	rd(N);
	repi(i, 1, N) {
		ll a, b;
		cin >> a >> b;
		edge ea, eb;
		ea.to = b, eb.to = a;
		nodes[a].push_back(ea);
		nodes[b].push_back(eb);
	}
	dfs(0, 1, 1);
	dfs(1, N, 1);
	repi(i, 1, N + 1) {
		if (costs[0][i] <= costs[1][i]) sum[0]++;
		else sum[1]++;
	}
	if (sum[0] > sum[1]) wrln("Fennec");
	else wrln("Snuke");
	return 0;
}
