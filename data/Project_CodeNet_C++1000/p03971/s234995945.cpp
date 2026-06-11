#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	int N, A, B; cin >> N >> A >> B;
	string S; cin >> S;
	vector<bool> ans(S.length(), false);
	int a = 0, b = 0;

	for (int i = 0; i < S.length();i++) {
		switch (S[i]) {
		case'a':
			if (a + b < A + B) {
				a++;
				ans[i] = true;
			}
			break;
		case'b':
			if (a + b < A + B && b < B) {
				b++;
				ans[i] = true;
			}
			break;
		case'c':
			break;
		}
	}

	for (bool flag : ans) {
		cout << (flag ? "Yes" : "No") << endl;
	}

	return 0;
}