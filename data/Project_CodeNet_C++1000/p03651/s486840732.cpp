#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x7ffffff;
const int mod = 1000000007;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	bool ok = true;
	if (a.back() < k) ok = false;
	int tmp = a.back();
	rep(i, n - 1) tmp = gcd(tmp, a[i]);
	if (k % tmp != 0) ok = false;
	if (ok) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}
