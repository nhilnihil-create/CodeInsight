#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<double, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll L;
	cin >> n >> L;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	int pos = -1;
	rep(i, n - 1) {
		if (a[i] + a[i + 1] >= L) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		cout << "Impossible" << endl;
		return 0;
	}
	vector<ll> ans;
	rep(i, pos) ans.push_back(i + 1);
	for (int i = n - 2; i >= pos; --i) ans.push_back(i + 1);
	cout << "Possible" << endl;
	for (int c : ans) cout << c << endl;
 	return 0;
}
