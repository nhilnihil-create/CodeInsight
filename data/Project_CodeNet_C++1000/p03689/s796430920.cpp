
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n,m,a,b; cin>>n>>m>>a>>b;
	int ans[n][m];
	for (int i = 0; i < n; i += a) 
	for (int j = 0; j < m; j += b) {
		for (int p = 0; p < a && i+p < n; p++)	
			for (int q = 0; q < b && j+q < m; q++)
				ans[i+p][j+q] = 4000;
		if (i+a-1<n && j+b-1<m)
			ans[i+a-1][j+b-1] = -((a*b-1)*4000+1);
	}	
	stringstream ss;
	ll cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			ss << ans[i][j] << " \n"[j==m-1];
			cnt += ans[i][j];
		}
	if (cnt > 0) cout << "Yes" << endl << ss.str();
	else cout << "No" << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

