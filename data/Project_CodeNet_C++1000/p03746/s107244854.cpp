#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
#include<deque>
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




signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<VI> G(N);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	deque<int> Q;
	vector<bool> vis(N, false);
	Q.push_front(0);
	Q.push_back(G[0][0]);
	vis[0] = true;
	vis[G[0][0]] = true;
	
	bool F = true;
	int s = 0;

	while (F) {
		bool f = true;
		REP(i, G[s].size()) {
			if (!vis[G[s][i]]) {
				Q.push_front(G[s][i]);
				s = G[s][i];
				vis[s] = true;
				f = false;
				break;
			}
		}
		if (f)F = false;
	}

	F = true;
	s = G[0][0];
	while (F) {
		bool f = true;
		REP(i, G[s].size()) {
			if (!vis[G[s][i]]) {
				Q.push_back(G[s][i]);
				s = G[s][i];
				vis[s] = true;
				f = false;
				break;
			}
		}
		if (f)F = false;
	}

	cout << Q.size() << endl;
	while (!Q.empty()) {
		cout << Q.front()+1;
		Q.pop_front();
		if (!Q.empty())cout << " ";
		else cout << endl;
	}
	return 0;
}

