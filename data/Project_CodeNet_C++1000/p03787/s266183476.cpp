#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


#define N 100010
vii M(N, vi()); //グラフの隣接リスト表現
vi color(N, -1);

//二部グラフかどうかを判断
bool bipartite(int s) {
	stack<int> st;
	color[s] = 0;
	st.push(s);
	int i, j;
	bool flag = true;
	while (!st.empty()) {
		i = st.top();
		st.pop();
		for (j = 0; j < M[i].size(); j++) {
			if (color[M[i][j]] == color[i]) {
				//cout << "NO" << endl;
				flag = false;
			}
			else {
				if (color[M[i][j]] == -1) {
					color[M[i][j]] = 1 - color[i];
					st.push(M[i][j]);
				}
			}
		}
	}
	//cout << "YES" << endl;
	return flag;
}

int main() {
	int n, m, i, j;
	cin >> n >> m;
	vector<bool> used(n, false);
	for (i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		M[u].push_back(v);
		M[v].push_back(u);
		used[u] = used[v] = true;
	}

	ll single = 0, nibu = 0, ki = 0;
	for (i = 0; i < n; i++) {
		if (!used[i]) {
			single++;
		}
		else {
			if (color[i] == -1) {
				if (bipartite(i)) {
					nibu++;
				}
				else {
					ki++;
				}
			}
		}
	}
	ll ans = 0;
	for (i = 0; i < single; i++) {
		ans += 2 * (n - i) - 1;
	}
	ans += 2 * nibu + ki;
	ans += 2 * nibu*(nibu - 1) + 2 * nibu * ki + ki * (ki - 1);
	cout << ans << endl;

}