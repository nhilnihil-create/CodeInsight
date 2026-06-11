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
#define double long double
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
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
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;

int N, M;
VI G[100010];
VI A, B, C;
int ans[100010];
bool done[100001][11];

void solve(int now, int d, int c) {
	//cout << now << " " << d << " " << c << endl;
	if (done[now][d])return;
	done[now][d] = 1;
	if(ans[now]==0)ans[now] = c;
	if (d == 0)return;
	solve(now, d - 1, c);	
	fore(to, G[now]) solve(to, d - 1, c);
}





signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	REP(i, M) {
		int v, u; cin >> v >> u;
		v--; u--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	int op; cin >> op;
	A.resize(op);
	B.resize(op);
	C.resize(op);
	REP(i, op) {
		cin >> A[i] >> B[i] >> C[i];
		A[i]--;
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());

	REP(i, op) {
		solve(A[i], B[i], C[i]);
		//cout << A[i] << endl;
	}
	REP(i, N)cout << ans[i] << '\n';

	return 0;
}

