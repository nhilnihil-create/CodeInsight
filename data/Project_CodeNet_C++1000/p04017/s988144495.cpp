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
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, L, q;
	cin >> N;
	VI X(N);
	REP(i, N)cin >> X[i];
	cin >> L >> q;


	int day[30][100010];
	//jから2のi乗日で進める個数

	REP(i, 30)REP(j, 100010)day[i][j] = INF * 10;


	int k = 0, s = 0, g = 0;

	while (k < N - 1) {
		if (g != N - 1) {
			while (X[g + 1] - X[s] <= L) {
				g++;
				if (g == N - 1)break;
			}
		}
		day[0][k] = g - s;
		k++;
		s++;
	}
	
	FOR(i, 1, 30) {
		REP(j, N - 1) {
			if (j + day[i-1][j] >= N -1)continue;
			day[i][j] = day[i - 1][j] + day[i - 1][j + day[i - 1][j]];
		}
	}
	
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (b < a)swap(a,b);
		int ans = 0;
		int now = a;
		
		do {
			bool F = true;

			for (int i = 25; i >= 0; i--) {
				if (day[i][now] + now <= b) {
					F = false;
					
					now += day[i][now];
					ans += (1LL << i);
					if (now == b) {
						F = true;
						break;
					}
				}
			}

			if (F) {
				if (now != b)ans++;
				cout << ans << endl;
				break;
			}
			else continue;

		} while (1);
	}
	return 0;
}

