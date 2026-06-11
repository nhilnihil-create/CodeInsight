#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 2147483647;
const ll LINF = 4223372036854775807;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

struct edge { ll from, to, cost; };
vector<edge> G;
vector<ll> d(200000, -LINF);

int main() {
	int n, m; cin >> n >> m;
	int a, b, c;
	REP(i,m) {
		cin >> a >> b >> c;
		G.push_back({a,b,c});
	}
	d[1] = 0;
	for (int i=0;i<n;i++) {
		bool up = false;
		REP(j,m) {	
			edge e = G[j];
			if (d[e.from] != -LINF && d[e.to] < d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				up = true;
				if (i==n-1&&e.to==n) {
					cout << "inf" << endl;
					return 0;
				}
			}
		}
		if (!up)
			break;
	}
	cout << d[n] << endl;
	return 0;
}