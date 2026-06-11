#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> sum(N + 1);
	sum[0] = 0;
	REP(i, N) {
		ll a;
		cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	ll res = INT64_MAX;
	REP(i, N - 1) {
		res = min(res, abs(sum[i + 1] - (sum[N] - sum[i + 1])));
	}
	cout << res << "\n";

	return 0;
}