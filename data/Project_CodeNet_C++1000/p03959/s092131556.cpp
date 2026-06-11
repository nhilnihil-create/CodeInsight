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



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N;
	cin >> N;
	VI T(N);
	VI A(N);
	REP(i, N) {
		cin >> T[i];
	}
	REP(i, N) {
		cin >> A[i];
	}
	
	VI mt(N);
	mt[0] = 1;
	int ma=T[0];
	if (ma > A[0]) {
		cout << 0 << endl;
		return 0;
	}

	FOR(i,1, N) {
		if (T[i - 1] != T[i]) {
			mt[i] = 1;
			ma = T[i];
			if (ma > A[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		else {
			mt[i] = ma;
		}
	}
	
	mt[N - 1] = 1;
	ma = A[N - 1];
	if (ma > T[N-1]) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] != A[i + 1]) {
			mt[i] = 1;
			ma = A[i];
			if (ma > T[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		else {
			mt[i] = min(ma, mt[i]);
		}
	}
	
	int ans = 1;
	REP(i, N) {
		ans = ans*mt[i] % mod;
	}
	if (N == 2 || N == 1) {
		cout << 1 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}

