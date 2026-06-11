#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
		if (s[i] == 'Z') {
			b = i;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'A') {
			a =  i;
		}
	}
    int ans = b - a +  1;
    if (ans < 0) {
		ans = 0;
	}
    cout << ans;
}

















