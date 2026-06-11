#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int maxm = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'I') {
			cnt++;
		}else {
			cnt--;
		}
		maxm = max(maxm,cnt);
	}
	cout << maxm;
}

















