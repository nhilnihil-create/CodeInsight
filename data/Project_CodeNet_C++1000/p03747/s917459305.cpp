
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; ll l,t;
	cin>>n>>l>>t;
	ll a[n],d[n];
	f(i,0,n) cin>>a[i]>>d[i];
	ll x = 0;
	f(i,0,n) x += d[i] == 1;

	ll fi = 0;
	if (d[0] == 1) {
		f(i,1,n) if (d[i] == 2)
			if (a[i]-a[0]<=2*t)
				fi = (fi+1+(2*t-a[i]+a[0])/l)%n; 
	} else {
		f(i,1,n) if (d[i] == 1)
			if (l+a[0]-a[i]<=2*t)
				fi = (fi+2*n-1-(2*t-l-a[0]+a[i])/l%n)%n;
	}

	ll b[n];
	int cnt = 0;
	f(i,0,n) if (d[i] == 1) b[i] = (a[i]+t)%l;
	else b[i]=(l+a[i]-t%l)%l;
	f(i,1,n) if (d[i] == 2 && b[i] == b[0]) cnt++;
	ll v = b[0];
	sort(b,b+n);
	int j = 0;
	while (b[j] != v) j++;
	f(_,0,cnt) j++;
	f(_,0,fi) j = (j-1+n)%n;
	stringstream ss;
	f(i,0,n) ss << b[(j+i)%n] << endl;	
	cout << ss.str();

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}
