#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;

int c;
string S, res;
stack<int>st;
bool B[26];

int main() {
	cin >> S;
	st.push(S.size());
	for (int i = S.size() - 1; i != -1; --i) {
		if (!B[S[i] - 'a']) {
			B[S[i] - 'a'] = true;
			++c;
			if (c == 26) {
				st.push(i);
				c = 0;
				memset(B, false, sizeof B);
			}
		}
	}
	memset(B, false, sizeof B);
	for (int i = 0; i != S.size(); ++i) {
		if (i == st.top()) {
			for (int j = 0; j != 26; ++j) {
				if (!B[j]) {
					res += j + 'a';
					break;
				}
			}
			memset(B, false, sizeof B);
			st.pop();
			while (i != S.size() && S[i] != res.back())
				++i;
			continue;
		}
		B[S[i] - 'a'] = true;
	}
	for (int j = 0; j != 26; ++j) {
		if (!B[j]) {
			res += j + 'a';
			break;
		}
	}
	cout << res << endl;
	return 0;
}
