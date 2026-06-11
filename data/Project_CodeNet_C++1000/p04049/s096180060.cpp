#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int N, K;
vector<VI> G(10000);
int dist[2010];

void dfs(int v, int p, int cur) {
	dist[v] = cur;
	for (int nv : G[v]) {
		if (nv == p)continue;
		dfs(nv, v, cur + 1);
	}
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N >> K;

	REP(i, N-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int ans = INF;

	if (K % 2 == 0) {
		REP(i, N) {
			dfs(i, -1, 0);
			int cnt = 0;
			REP(j, N)if (dist[j] > K / 2)cnt++;
			ans = min(ans, cnt);
		}
	}
	else {
		REP(u, N) {
			for (int v : G[u]) {
				dist[v] = 0;
				dfs(u, v, 0);
				dfs(v, u, 0);
				int cnt = 0;
				REP(a, N)if (dist[a] > K / 2)cnt++;
				ans = min(ans, cnt);
			}
		}
	}
	cout << ans << endl;

	return 0;
}

