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

	int N, K, sum = 0;
	cin >> N;
	VI A(N), d(N);
	bool F = true;
	REP(i, N) {
		cin >> A[i];
		sum += A[i];
	}
	if (sum % (N*(N + 1) / 2) != 0)F = false;
	K = sum / (N*(N + 1) / 2);



	REP(i, N) {
		if (i == N - 1) {
			d[i] = A[0] - A[i];
		}
		else {
			d[i] = A[i + 1] - A[i];
		}
	}
	REP(i, N) {
		if (K < d[i])F = false;
		if ((K - d[i]) % N != 0)F = false;
	}

	cout << (F ? "YES" : "NO") << endl;







	return 0;
}

