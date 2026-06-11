#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> 
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

map<pii, LL> mp;
int H, W, N;
LL ans[10];

bool inbounds(int a, int b) {
	return a >= 0 && b >= 0 && a < H && b < W;
}
void add(int a, int b) {
	if (!inbounds(a, b) || !inbounds(a + 2, b + 2)) {
		return;
	}
	mp[pii(a, b)]++;
}
int main() {
	scanf("%d%d%d", &H, &W, &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;

		for (int x = -2; x <= 0; x++) {
			for (int y = -2; y <= 0; y++) {
				add(a + x, b + y);
			}
		}
	}

	LL sum = 0;
	for (map<pii, LL>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
		ans[itr->second]++;
	}
	for (int i = 0; i < 10; i++) {
		sum += ans[i];
	}

	LL zeros = ((LL)H - 2) * ((LL)W - 2) - sum;
	cout << zeros << '\n';
	for (int i = 1; i < 10; i++) {
		cout << ans[i] << '\n';
	}
}