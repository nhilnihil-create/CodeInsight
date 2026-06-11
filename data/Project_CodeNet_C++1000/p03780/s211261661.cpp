#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
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



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	VI A(N);
	int sum = 0;
	REP(i, N) {
		cin >> A[i];
		sum += A[i];
	}
	rSORT(A);
	int res = 0;
	vector<bool> dp(K);
	dp[0] = true;
	REP(i, N) {
		bool f = false;
		REP(j, K) {
			f |= dp[j] && j + sum >= K;
		}
		if (!f) 
			res++;

		sum -= A[i];
		for (int j = K - 1 - A[i]; j >= 0; j--) {
			dp[j + A[i]] = dp[j + A[i]] | dp[j];
		}
	}

	cout << res << endl;
	return 0;
}

