#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
	int N, s[MAX], S = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		S += s[i];
	}
	if (S % 10 != 0) {
		cout << S << endl;
		return 0;
	} else {
		sort(s, s + N);
		for (int i = 0; i < N; i++) {
			if ((S - s[i]) % 10 != 0) {
				cout << S - s[i] << endl;
				return 0;
			}
		}
		cout << 0 << endl;
	}
	return 0;
}
