#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

const ll inf = 1e9;


int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> rs(r);
	rep(i, r) {
		cin >> rs[i];
		rs[i] --;
	}
	sort(rs.begin(),rs.end());

	ll d[n][n];
	rep(i,n) rep(j,n) {
		d[i][j] = i == j ? 0 : inf;
	}


	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		
		d[a][b] = c;
		d[b][a] = c;

	}



	rep(k, n) rep(i, n) rep(j,n) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

	ll ans = inf;
	do {
		ll total = 0;
		rep(i, r - 1) {
			total += d[rs[i]][rs[i+1]];
		}
		//cout << "total:" << total << endl;
		ans = min(total,ans);



  	} while ( next_permutation(rs.begin(),rs.end()));

  	cout << ans << endl;

	return 0;
}
