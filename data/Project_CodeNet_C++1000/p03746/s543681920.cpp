#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
void chmin(int &a, int b) { if (a > b) a = b; }

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll MOD = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char da[4] = { 'R', 'L', 'D', 'U' };
char dax[4] = { -1, 1, -1, 1 };
char dax2[4] = { 1, -1, 1, -1 };
ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
ll max(ll a, ll b) { return (a > b) ? a : b; }
template<typename T>
struct edge {

	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	bool operator<(const edge<T> e1) {
		return cost < e1.cost;
	}


	edge &operator=(const int &x) {
		to = x;
		return *this;
	}

	operator int() const { return to; }

};
template<typename T>
using Edge = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edge<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

int vis[100005];
UnWeightedGraph G;
vector<int> solve(int s) {
	stack<int> sta;
	vector<int> ans;
	sta.push(s);
	ans.push_back(s);
	while (!sta.empty()) {
		ll cur = sta.top();
		vis[cur] = 1;
		sta.pop();
		rep(i, G[cur].size()) {
			if (vis[G[cur][i]] == 0) {
				sta.push(G[cur][i]);
				ans.push_back(G[cur][i]);
				break;
			}
		}
	}

	rep(i, G[s].size()) {
		if (vis[G[s][i]] == 0) {
			sta.push(G[s][i]);
			ans.insert(ans.begin(), G[s][i]);
			break;
		}
	}

	while (!sta.empty()) {
		ll cur = sta.top();
		vis[cur] = 1;
		sta.pop();
		rep(i, G[cur].size()) {
			if (vis[G[cur][i]] == 0) {
				sta.push(G[cur][i]);
				ans.insert(ans.begin(), G[cur][i]);
				break;
			}
		}


	}

	return ans;
}


int main() {
	ll N, M;

	cin >> N >> M;
	G.resize(N);
	rep(i, M) {
		ll A, B;
		cin >> A >> B;
		A--, B--;
		G[A].emplace_back(B);
		G[B].emplace_back(A);
	}


	vector<int> ans = solve(0);

	cout << ans.size() << endl;

	rep(i, ans.size()) {
		cout << ans[i]+1 << " ";
	}
	
	return 0;

}