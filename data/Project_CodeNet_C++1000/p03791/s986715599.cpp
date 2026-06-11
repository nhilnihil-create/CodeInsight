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
#define MOD 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

const int SIZE = 100010;
ll inv[SIZE], fac[SIZE], finv[SIZE];
void make() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < SIZE; i++) {
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		fac[i] = fac[i - 1] * (ll)i%MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	make();

	int N;
	cin >> N;
	VI A(N);
	REP(i, N) cin >> A[i];

	int ans = 1;
	int i = 0, j = 1;
	int cnt = 1, cntt = 0;

	while (i < N) {
		if (A[i] >= j) {
			A[i] = j;
			j += 2;
			cnt++;
		}
		else {
			cntt++;
			ans *= cnt;
			//cnt = 0;
		}
		i++;
		ans %= mod;
	}
	
	//cout << cntt << endl;
	ans *= fac[N - cntt];
	ans %= mod;
	cout << ans << endl;
	
	return 0;
}

