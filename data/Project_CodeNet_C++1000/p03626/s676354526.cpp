#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, pair<int, int>>PP;
typedef long long ll;
ll inf = -1;

int main() {
	int n; cin >> n;
	ll mod = 1000000007;
	string s1, s2;
	cin >> s1 >> s2;
	int j;
	ll ans = 1;
	int type;
	if (s1[0] == s2[0]) {
		type = 0;
		ans *= 3;
		j = 1;
	}
	else {
		type = 1;
		ans *= 6;
		j = 2;
	}
	while (j < n) {
		if (s1[j] == s2[j]) {
			if (type == 0) {
				ans *= 2;
			}
			ans %= mod;
			type = 0;
			j++;
		}
		else {
			if (type == 0) {
				ans *= 2;
			}
			else {
				ans *= 3;
			}
			ans %= mod;
			type = 1;
			j += 2;
		}
	}
	cout << ans << endl;
	return 0;
}