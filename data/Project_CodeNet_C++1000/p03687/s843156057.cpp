#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
//const ll INF = 1LL<<60;
int INF = numeric_limits<int>::max();

int main(int, char**) {
	string t; cin >> t;
	int n = t.size();
	int ret = INF;
	for (char c='a'; c<='z'; c++) {
		int ma = 0;
		int cnt = 0;
		for (int i=0; i<n; i++) {
			cnt++;
			if (t[i]==c) {
				ma = max(ma, cnt - 1);
				cnt = 0;
			} else if (i==n-1) {
				ma = max(ma, cnt);
			}
		}
		ret = min(ret, ma);
	}
	cout << ret << endl;
	return 0;
}
