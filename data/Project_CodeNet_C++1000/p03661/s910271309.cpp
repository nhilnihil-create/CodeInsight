#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//infinity
#define INTINF 2000000000
#define LONGINF 2000000000

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
	int n; cin >> n;
	long long a[n];
	REP(i, n) cin >> a[i];

	long long x = a[0];
	long long y = 0;
	FOR(i, 1, n) y += a[i];
	long long ans = abs(x - y);

	FOR(i, 1, n - 1){
		x += a[i];
		y -= a[i];
		ans = min(ans, abs(x-y));
	}
	cout << ans << endl;
	return 0;
}
