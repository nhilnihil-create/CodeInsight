#include <bits/stdc++.h>
const int MOD = 1e9+7;
#define REP(i,n) for (int i = 0; i < (N); ++i)
#define ar array
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int ans = 0;

	for (int i = 0; i <= N; i++) {
		ans = ans + i; 
	}
	cout << ans << endl;
	return 0;
}
