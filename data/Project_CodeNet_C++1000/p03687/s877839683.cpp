#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, i, j, le[27][103] = {}, sans, ans;
	string s;

	cin >> s;

	n = s.size();

	for (i = 0; i < 26; i++) {
		le[i][0] = -1;
	}

	for (i = 0; i < n; i++) {
		le[s[i] - 'a'][i] = i;
	}

	for (i = 0; i < 26; i++) {
		for (j = 1; j < n; j++) {
			if (le[i][j] == 0) le[i][j] = le[i][j - 1];
		}
		le[i][n] = n;
	}

	ans = INF;
	for (i = 0; i < 26; i++) {
		sans = 0;
		for (j = 1; j <= n; j++) {
			if (le[i][j] != le[i][j - 1]) {
				sans = max(sans, le[i][j] - le[i][j - 1] - 1);
			}
		}
		ans = min(ans, sans);
	}

	printf("%d\n", ans);

	return 0;
}