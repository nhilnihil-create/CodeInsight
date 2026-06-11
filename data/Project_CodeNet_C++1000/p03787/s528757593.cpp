#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
int kai_size = 100001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
int RE() {
	vel v(3, 2);
	return v.at(4);
}
void dis(int mid1, vvel &way,vel &conect) {
	int n = way.size();
	dist[mid1] = 0;
	queue<int> q;
	q.push(mid1);
	while (!q.empty()) {
		int st = q.front(); 
		conect.push_back(st);
		q.pop();
		rep(i, way[st].size()) {
			int to = way[st][i];
			if (dist[to] == -1) { 
				dist[to] = dist[st] + 1;
				q.push(to);
			}
		}
	}
}

signed main() {
	int n, m; cin >> n >> m;
	vvel way(n);
	rep(i, m) {
		int u, v; cin >> u >> v;
		u--; v--;
		way[u].push_back(v);
		way[v].push_back(u);
	};
	V<pin> list(0);
	dist = vel(n, -1);
	int nibu = 0;
	int not_nibu = 0;
	int only_one = 0;
	rep(i, n) {
		if (dist[i] == -1) {
			vel conect(0);
			dis(i, way, conect);
			if (conect.size() == 1) { only_one++; }
			else {
				bool is_nibu = true;
				for(auto st: conect) {
					for (auto to: way[st]) {
						if ((dist[st] + dist[to]) % 2 == 0) { is_nibu = false; }
					}
				}
				if (is_nibu) { nibu++; }
				else { not_nibu++; }
			}
		}
	}
	int ans = sq(n) - sq(n-only_one);
	ans += sq(nibu) + sq(nibu + not_nibu);
	cout << ans << endl;
	return 0;
}
