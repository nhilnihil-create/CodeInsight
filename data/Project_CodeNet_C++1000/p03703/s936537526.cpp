#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
const int maxn = 200010;

int ft[maxn];
int n,k;

int ls(int x) {
	return x & (-x);
}

void up(int x) {
	for (;x <= n;x += ls(x)) ft[x]++;
}

int query(int x) {
	int res = 0;
	for (;x; x -= ls(x)) res += ft[x];
	return res;
}

int32_t main() {
	FAST
	cin >> n >> k;
	vector <pi> v;
	int curs = 0;
	for (int i =1;i<=n;i++) {
		int x; cin >> x;
		curs += x;
		v.push_back(pi(curs - i*k,i));
		//cout << i << " " << x-i*k << "\n";
	}
	sort(v.begin(),v.end());
	int ans = 0;
	for (auto cur: v) {
		if (cur.f >= 0) ans++;
		ans += query(cur.s);
		up(cur.s);
		//cout << cur.f << " " << cur.s << " " << ans << "\n";
	}
	
	cout << ans;
	
}







