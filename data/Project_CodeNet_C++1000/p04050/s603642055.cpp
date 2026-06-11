#include <bits/stdc++.h>
using namespace std;
 
#define f(i,a,b) for (int i = a; i < b; i++)
using vi = vector<int>;
#define pb push_back
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> m >> n;
	int a[n];
	f(i,0,n) cin>>a[i];
	int cnt = 0;
	f(i,0,n) cnt += a[i]&1;
	if (n == 1) {
		cout << a[0] << endl;
		if (a[0] == 1) cout << 1 << endl << 1 << endl;
		else cout << 2 << endl << a[0]-1 << " " << 1 << endl;
		return 0;
	}
	if (cnt>2) {
		cout << "Impossible" << endl;
		return 0;
	}
	f(i,0,n) if (a[i]&1) swap(a[i],a[0]);
	f(i,1,n) if (a[i]&1) swap(a[i],a[n-1]);
	vi ans;
	f(i,0,n) if (!i && a[i]-1) ans.pb(a[i]-1);
		else if (i) ans.pb(a[i] + (i==n-1));
	stringstream ss;
	f(i,0,n) ss << a[i] << " ";
	ss << endl << ans.size() << endl;
	for (int x : ans) ss << x << " ";
	cout << ss.str() << endl;
	return 0;
}