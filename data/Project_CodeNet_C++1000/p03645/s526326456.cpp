#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector< vector<int> > G(n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	vector<int> dist(n, 1e9 + 1);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	
	while( !q.empty() ) {
		int now = q.front();
		q.pop();
		
		for(auto& v : G[now]) {
			if( dist[v] > dist[now] + 1 ) {
				dist[v] = dist[now] + 1;
				q.push(v);
			}
		}
	}
	
	if( dist[n - 1] == 2 ) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	
	return 0;
}
