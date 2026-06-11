#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') st.push(s[i]);
		else if (s[i] == '1') st.push(s[i]);
		else {
			if (!st.empty()) st.pop();
		}
	}
	string ans = "";
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
    return 0;
}