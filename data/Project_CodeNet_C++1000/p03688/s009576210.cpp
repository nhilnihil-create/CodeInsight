
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i <b ; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin>>n;
	int freq[n+1];
	fill(freq,freq+n+1,0);
	f(i,0,n) {
		int a; cin>>a;
		freq[a]++;
	}
	bool found = 0;
	f(a,0,n) {
		int k = freq[a];
		if (a+1>=k+(n-k>0) && 2*(a+1-k) <= n-k && freq[a+1]==n-k)
			found = 1;
	}
	cout << (found?"Yes":"No") << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

