#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll n, m, x, y, sum, mx, a[100005], s[200005];
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<n; i++) {
		x = a[i]; y = a[i+1];
		if(x > y) y += m;
		sum += y-x;
		if(y-x <= 1) continue;
		s[x+2]++;
		s[y+1] -= y-x;
		s[y+2] += y-x-1;
	}
	for(int i=1; i<=2*m; i++) s[i] += s[i-1];
	for(int i=1; i<=2*m; i++) s[i] += s[i-1];
	for(int i=1; i<=m; i++) mx = max(mx, s[i] + s[i+m]);
	cout << sum - mx << endl;
	return 0;
}
