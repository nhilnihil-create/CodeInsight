#include <bits/stdc++.h>

using namespace std;

#define ll long long

char resp[5];

char query(ll x) {
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", resp);
	return resp[0];
}
ll p10[13];
ll bs(int len) {
	ll start = p10[len], End = p10[len + 1] - 1, ans = 0;
	while (start <= End) {
		auto mid = (start + End) / 2;
		if (query(mid) == 'N') {
			ans = mid;
			start = mid + 1;
		}
		else End = mid - 1;
	}
	return ans;
}
void Finish(ll val) {
	printf("! %lld\n", val);
	fflush(stdout);
	exit(0);
}
int main() {
	//freopen("oj.in", "r", stdin);
	p10[0] = 1;
	for (int i = 1; i <= 11; ++i)
		p10[i] = p10[i - 1] * 10;
	int len = 1;
	for (int i = 10; i >= 1; --i) {
		ll curr = p10[i];
		if (query(curr) == 'Y') {
			len = i;
			break;
		}
	}
	auto mayb = bs(len + 1);
	if (mayb == 0) {
		for (int i = 1; i <= 10; ++i) {
			if (query(p10[i] - 1) == 'Y') {
				Finish(p10[i - 1]);
			}
		}

	}
	else {
		mayb = mayb / 10 + 1;
		if (mayb / 100 == 0 && mayb % 10 == 0) {
			if (query(mayb / 10) == 'Y')mayb /= 10;
		}
		Finish(mayb);
	}
	return 0;
}
