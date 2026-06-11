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
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VI mo(M, 0);
	VI A(N);
	int cnt[100010] = { 0 };
	REP(i, N) {
		int a; cin >> a;
		cnt[a]++;
		mo[a%M]++;
		A[i] = a;
	}

	int ans = 0;
	int o = 1, p = M - 1;
	while (o <= p) {
		if (o == p) {
			ans += mo[o] / 2;
			mo[o] = mo[o] % 2;
		}
		else {
			int tmp = min(mo[o], mo[p]);
			ans += tmp;
			mo[o] -= tmp;
			mo[p] -= tmp;
		}
		o++;
		p--;
	}


	REP(i, N) {
		int a = A[i];
		int tmp= min(mo[a%M] / 2, cnt[a] / 2);
		ans += tmp;
		mo[a%M] -= tmp * 2;
		cnt[a] -= tmp * 2;
	}




	cout << ans + mo[0] / 2 << endl;
	return 0;
}

