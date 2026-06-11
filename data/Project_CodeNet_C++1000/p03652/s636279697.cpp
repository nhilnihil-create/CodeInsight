
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n,m; cin>>n>>m;
	int a[n][m];
	f(i,0,n) f(j,0,m) cin>>a[i][j];
	f(i,0,n) f(j,0,m) a[i][j]--;
	bool take[m];	
	f(i,0,m) take[i] = 1;
	int ans = oo;
	f(_,0,m) {
		int freq[m];
		fill(freq,freq+m,0);
		f(i,0,n) {
			int k = 0;	
			fr(j,0,m) if (take[a[i][j]]) k = a[i][j];
			freq[k]++;
		}
		int k = 0;
		f(i,1,m) if (freq[k]<freq[i])
			k=i;
		ans = min(ans,freq[k]);
		take[k] = 0;
	}	
	cout << ans << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

