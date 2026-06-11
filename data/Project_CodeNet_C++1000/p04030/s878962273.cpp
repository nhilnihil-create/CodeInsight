#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> st;

	for (int i=0; i<str.length(); i++) {
		if (str[i] == 'B' ) {
			if (!st.empty())
				st.pop();
		}
		else {
			st.push(str[i]);
		}
	}

	vector<char> res;
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}

	for (int i=res.size()-1; i>=0; i--)
		cout << res[i];
	return 0;
}