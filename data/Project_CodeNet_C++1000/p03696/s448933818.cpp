#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
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
			st.push(0);
		}
		else {
			if (st.size() == 0);
			else {
				if (st.top() == 0) st.pop();
			}
		}
	}
	int a = st.size();
	stack<int> st2;
	reverse(all(s));
	rep(i, n) {
		if (s[i] == ')') {
			st2.push(0);
		}
		else {
			if (st2.size() == 0) ;
			else {
				if (st2.top() == 0) st2.pop();
			}
		}
	}
	reverse(all(s));
	rep(i, st2.size()) cout << '(';
	rep(i, n) cout << s[i];
	rep(i, a) cout << ')';
	cout << endl;
	return 0;
}
