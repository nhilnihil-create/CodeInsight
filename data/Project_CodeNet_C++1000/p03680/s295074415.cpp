#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) {
		cin >> v[i];
		v[i]--;
	}
	vector<int> flag(n);
	int cur = 0;
	int cnt = 0;
	while (true) {
		if (cur == 1) {
			cout << cnt << endl;
			return 0;
		}
		if (flag[cur]) {
			cout << -1 << endl;
			return 0;
		}
		flag[cur]++;
		cnt++;
		cur = v[cur];
	}
}