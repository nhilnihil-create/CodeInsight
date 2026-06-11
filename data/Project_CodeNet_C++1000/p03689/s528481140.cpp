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
#define INF 10000
#define LLINF 9223372036854775807
#define mod 1000000007
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W, h, w; cin >> H >> W >> h >> w;

	if (H%h == 0 && W % w == 0) {
		cout << "No" << endl;
		return 0;
	}
	int sum = 0;
	vector<VI> ans(H, VI(W, -INF));
	if (H%h) {
		int ma = (h - 1)*w*INF / w - 10;
		int cnt = 0;
		REP(i, H) {
			if (i%h)continue;
			REP(j, W) {
				ans[i][j] = ma;
			}
		}
	}
	else {
		int ma = (w - 1)*h*INF / h - 10;
		int cnt = 0;
		REP(i, H) {
			//if (i%h)continue;
			REP(j, W) {
				if (j%w)continue;
				ans[i][j] = ma;
			}
		}
	}
	

	
	//cout << ma << endl;
	cout << "Yes" << endl;
	REP(i, H) {
		REP(j, W) {
			cout << ans[i][j] << " ";
			sum += ans[i][j];
			//printf("%2lld ", ans[i][j]);
		}
		cout << endl;
	}
	//cout << sum << endl;

	return 0;
}

