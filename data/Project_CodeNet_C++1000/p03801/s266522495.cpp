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

	int N, sum = 0;
	cin >> N;
	VP A(N);
	VI ans(N, 0);
	VI B(N);
	map<int, int>mp;
	REP(i, N) {
		cin >> A[i].first;
		sum += A[i].first;
		A[i].second = -i;
		mp[A[i].first]++;
		B[i] = A[i].first;
	}

	vector<bool>F(N, false);
	int ma = 0;
	REP(i, N) {
		if (ma < A[i].first) {
			ma = A[i].first;
			F[i] = 1;
			//cout << i << endl;
		}
	}
	SORT(B);
	VI cnt(N + 1, 0);
	REP(i, N)cnt[i + 1] = cnt[i] + B[i];

	REP(i, N) if(F[i]){
		
		int a = A[i].first;
		int b = UB(B, a) - B.begin();
		
		ans[i] = sum - (cnt[N] - cnt[b] - a * (N - b));
		sum -= ans[i];
	}

	REP(i, N)cout << ans[i] << '\n';

	return 0;
}

