#include <iostream>
#include <string>
using namespace std;
int MOD = 1000000007;

int main() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	long long ans = 3;
	bool bv = false;
	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i]) {
			if (i) {
				if (bv) ans = (ans * 2) % MOD;
			}
			else ans = 3;
			bv = true;
		}
		else {
			if (i) {
				if (bv) ans = (ans * 2) % MOD;
				else ans = (ans * 3) % MOD;
			}
			else ans = 6;
			i++;
			bv = false;
		}
	}
	cout << ans << endl;
}