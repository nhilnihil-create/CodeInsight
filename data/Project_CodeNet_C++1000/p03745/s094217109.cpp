#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll linf = (1LL << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	stack<int> st;
	int pos = 0;
	int ans = 0;
	rep(i, n) {
		if (st.size() == 0) {
			st.push(a[i]);
			continue;
		}
		if (pos == 0) {
			if (st.top() < a[i]) pos = 1, st.push(a[i]);
			else if (st.top() > a[i]) pos = -1, st.push(a[i]);
			else st.push(a[i]);
		}
		else if (pos == 1) {
			if (st.top() <= a[i]) st.push(a[i]);
			else {
				while (st.size()) st.pop();
				ans++;
				st.push(a[i]);
				pos = 0;
			}
		}
		else {
			if (st.top() >= a[i]) st.push(a[i]);
			else {
				while (st.size()) st.pop();
				ans++;
				st.push(a[i]);
				pos = 0;
			}
		}
	}
	if (st.size()) ans++;
	cout << ans << endl;
	return 0;
}