#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

string solve(string& s) {
	for (int i = 0; i < 26; ++i) {
		bool found = false;
		for (int j = 0; j < s.length(); ++j)
			found |= s[j] == ('a' + i);
		if (!found) {
			string res = "a";
			res[0] = (res[0] + i);
			return res;
		}
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			string tmp = "aa";
			tmp[0] = (tmp[0] + i);
			tmp[1] = (tmp[1] + j);
			bool found = false;
			int ptr = 0;
			for (int k = 0; k < s.length(); ++k) {
				if (s[k] == tmp[ptr]) {
					++ptr;
					if (ptr == 2) {
						found = true;
						break;
					}
				}
			}
			if (!found)
				return tmp;
		}
	}
}

int main() {
	string A; cin >> A;
	int f = 0;
	vector<string> A_part;
	string tmp = "";
	for (int i = A.length() - 1; i >= 0; --i) {
		tmp = A[i] + tmp;
		f |= (1 << (A[i] - 'a'));
		if (f == (1 << 26) - 1) {
			A_part.push_back(tmp);
			f = 0; tmp = "";
		}
	}
	A_part.push_back(tmp);

	reverse(A_part.begin(), A_part.end());

	string res = solve(A_part[0]);
	string lst_added = res;
	for (int i = 1; i < A_part.size(); ++i) {
		int ptr = 0;
		int idx = 0;
		while (i < A_part.size() && ptr < lst_added.length()) {
			while (idx < A_part[i].length() && A_part[i][idx++] != lst_added[ptr]);
			if (A_part[i][idx - 1] == lst_added[ptr])
				++ptr;
			else {
				++i; idx = 0;
			}
		}
		if (i == A_part.size()) break;
		string tmp = A_part[i].substr(idx, A_part[i].length() - idx);
		res += (lst_added = solve(tmp));
	}

	cout << res << endl;

	return 0;
}