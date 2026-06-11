#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin>> S;
	int now = 0;
	int ans = now;
	for (int i = 0;i<S.size();++i) {
		if ('I'==S[i]) {
			now++;
		}
		else {
			now--;
		}
		ans = max(ans, now);
	}
	cout << ans<<endl;
	return 0;
}