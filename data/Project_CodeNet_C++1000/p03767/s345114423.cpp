#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	int N; cin >> N;
	vector<int> a(3*N);
	REP(i,3*N) cin >> a[i];

	SORT(a);
	ll ans = 0;
	REP(i,N) ans += a[3*N-2*(i+1)];

	cout << ans << endl;






	return 0;

}
