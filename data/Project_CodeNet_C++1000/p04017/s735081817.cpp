#include <bits/stdc++.h>
using namespace std;

int N, x[100001], L, Next[100001], Used[100001][2], Q, a, b;
vector<int>v[100001];


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i];
	}
	cin >> L;
	int r = 1;
	for (int i = 1; i <= N; i++) {
		while (x[i] + L >= x[r] && r <= N) {
			r++;
		}
		Next[i] = r - 1;
	}
	for (int i = 1;; i = Next[i]) {
		Used[i][0] = 1;
		Used[i][1] = v[1].size();
		v[1].push_back(i);
		if (i == N)break;
	}
	for (int i = 2; i <= N; i++) {
		if (Used[i][0])continue;
		for (int j = i;; j = Next[j]) {
			if (Used[j][0]) {
				v[i].push_back(j);
				break;
			}
			Used[j][0] = i;
			Used[j][1] = v[i].size();
			v[i].push_back(j);
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> a >> b;
		if (a > b)swap(a, b);
		int ans = 0;
		while (a != b) {
			if (v[Used[a][0]].back() < b) {
				ans += v[Used[a][0]].size() - Used[a][1] - 1;
				a = v[Used[a][0]].back();
			}
			else {
				ans += lower_bound(v[Used[a][0]].begin(), v[Used[a][0]].end(), b) - v[Used[a][0]].begin() - Used[a][1];
				break;
			}
		}
		cout << ans << endl;
	}
}