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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	VI A(N);
	VI sum(N + 1);
	VI ssum(N + 1);
	sum[0] = 0;
	ssum[0] = 0;
	REP(i, N) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
		ssum[i + 1] = ssum[i];
		if (A[i] > 0)ssum[i + 1] += A[i];
		//cout << sum[i + 1] << endl;
	}

	int ans = LLINF * -1;
	eFOR(i, K, N) {
		//cout << ssum[N] + (sum[i] - sum[i - K]) << " " << ssum[N] - (ssum[i] - ssum[i - K]) << endl;
		ans = max(ssum[N] + (sum[i] - sum[i - K])-(ssum[i]-ssum[i-K]), ans);
		ans = max(ssum[N] - (ssum[i] - ssum[i - K]), ans);
	}
	cout << max(0LL, ans) << endl;
	
	return 0;
}

