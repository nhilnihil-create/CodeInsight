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

	int N; cin >> N;
	VI A(N);
	VI cnt(N, 0);
	int mi = INF, ma = -1;
	REP(i, N) {
		cin >> A[i];
		cnt[A[i]]++;
		chmin(mi, A[i]);
		chmax(ma, A[i]);
	}
	rSORT(A);
	bool F = 1;
	int type = 1;
	if (ma % 2)type++;
	eFOR(i, mi, ma) {
		//cout << F << endl;
		if (i == mi && cnt[i] != type)F = 0;
		else if (i == mi)continue;
		if (cnt[i] < 2)F = 0;
		else if (cnt[i] == 0)F = 0;
	}
	//cout << F << endl;
	if ((ma + 1) / 2 != mi)F = false;

	if (F)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}

