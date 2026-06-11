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
const ll linf = (ll)4e18;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	deque<int> deq;
	bool now = 1;
	rep(i, n) {
		if (now) {
			deq.push_back(a[i]);
			now = 0;
		}
		else {
			deq.push_front(a[i]);
			now = 1;
		}
	}
	if (!now) reverse(all(deq));
	rep(i, n) cout << deq[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}
