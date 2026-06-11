#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> used(1000000, 0), same(M, 0), num(M, 0);
	for (int i = 0, X; i < N; i++) {
		cin >> X;
		num[X % M]++;
		used[X]++;
		if (used[X] % 2 == 0) {
			same[X % M]++;
		}
	}
	long long res = 0;
	vector<bool> Used(M, false);
	for (int i = 0; i < M; i++) {
		if (i == (M - i) % M) {
			if (Used[i]) continue;
			res += num[i] / 2;
			num[i] %= 2;
			Used[i] = true;
		}
		else {
			if (Used[i] && Used[(M - i) % M]) continue;
			int val = min(num[i], num[(M - i) % M]);
			if ((num[i] - val) % 2 && (num[(M - i) % M] - val) % 2 && same[i] * 2 > val && same[(M - i) % M] * 2 > val) val--;
			res += val;
			num[i] -= val;
			num[(M - i) % M] -= val;
			res += min(num[i], same[i] * 2) / 2;
			num[i] -= min(num[i], same[i] * 2) / 2 * 2;
			res += min(num[(M - i) % M], same[(M - i) % M] * 2) / 2;
			num[(M - i) % M] -= min(num[(M - i) % M], same[(M - i) % M] * 2) / 2 * 2;
			Used[i] = Used[(M - i) % M] = true;
		}
	}
	cout << res << endl;
	return 0;
}
