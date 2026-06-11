
// D - Insertion

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int unpaired_r = 0;
	int l = 0;
	for (int i=0; i<N; i++) {
		if (S[i] == ')') {
			if (l == 0) {
				unpaired_r++;
			} else {
				l--;
			}
		} else {
			l++;
		}
	}

	int unpaired_l = 0;
	int r = 0;
	for (int i=N-1; i>=0; i--) {
		if (S[i] == '(') {
			if (r == 0) {
				unpaired_l++;
			} else {
				r--;
			}
		} else {
			r++;
		}
	}

	string ans = S;
	for (int i=0; i< unpaired_r; i++) {
		ans = '(' + ans;
	}
	for (int i=0; i< unpaired_l; i++) {
		ans = ans + ')';
	}

	cout << ans << endl;

	return 0;
}