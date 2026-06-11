#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[345678], kari[345678];
signed main() {
	int n, a, ans = 0; cin >> n;
	map<int, int> cnt;
	for (int h = 0; h < n; h++) {
		cin >> test[h]; kari[h] = test[h];
	}
	sort(kari, kari + n);
	for (int h = 0; h < n; h += 2) {
		cnt[kari[h]] = 1;
	}
	for (int h = 0; h < n; h += 2) {
		if (cnt[test[h]] == 0) { ans++; }
	}
	cout << ans << endl;
	return 0;
}