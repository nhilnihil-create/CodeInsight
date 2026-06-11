#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N, M; cin >> N >> M;
	vector<int> x(M), y(M);
	rep(i, M) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}

	vector<int> num(N, 1);
	vector<bool> red(N, false);
	red[0] = true;

	rep(i, M) {
		num[x[i]]--;
		num[y[i]]++;
		if (red[x[i]])red[y[i]] = true;
		if (num[x[i]] == 0)red[x[i]] = false;
	}

	int ans = 0;
	rep(i, N) {
		if (red[i])ans++;
	}
	cout << ans << endl;

	return 0;
}