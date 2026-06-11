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
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	stack<int> st;
	rep(i, n) {
		if (s[i] == '(') {
			st.push(1);
		}
		else {
			if (st.size() && st.top() == 1) st.pop();
			else st.push(0);
		}
	}
	int cnt0 = 0, cnt1 = 0;
	while (st.size()) {
		if (st.top() == 1) cnt1++;
		else cnt0++;
		st.pop();
	}
	rep(i, cnt0) cout << '(';
	cout << s;
	rep(i, cnt1) cout << ')';
	cout << endl;
	return 0;
}
