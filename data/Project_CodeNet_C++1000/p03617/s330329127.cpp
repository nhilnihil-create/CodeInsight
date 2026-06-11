#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, h, s, d;
	cin >> q >> h >> s >> d;
	int n;
	cin >> n;
	q *= 4;
	h *= 2;
	mins(s, q);
	mins(s, h);
	if (n % 2 == 0) {
		s *= 2;
		mins(d, s);
		cout << ll(n / 2) * d << endl;
	}
	else {
		if (2 * s >= d) {
			cout << ll((n - 1) / 2) * d + s << endl;
		}
		else {
			cout << (ll)n * s << endl;
		}
	}
	return 0;
}