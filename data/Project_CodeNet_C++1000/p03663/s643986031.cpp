#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, S;

int hp (ll x) {
	static char ss[] = "87";
	static char s[20];
	sprintf(s, "%lld", x);
	return ((string)s < (string)ss) == (x < 87);
}

bool ask (bool p, ll x) {
	static char y;
	printf("%c %lld\n", p ? '!' : '?', x);
	fflush(stdout);
	scanf("%s", &y);
//	return hp(x);
	return y == 'Y';
}

int main () {
	int res = 0, j = 1, now = ask(0, 1000000000000ll) ^ 1;
	bool oo;
	for (int i = 9, j = 1, _i = 10; 1; i = i * 10 + 9, ++j, _i *= 10) {
		if (now == 0) oo = ask(0, i);
		else oo = !ask(0, _i);
		if (oo) { S = j; break; }
		if (i == 1e9) { S = 9; break; }
	}
	if (!S) return ask(1, 0), 0;
	if (S == 10) return ask(1, 1e9), 0;
	for (int i = j = 1; i < S; ++i, res *= 10) {
		int l = 1, r = 9, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (!ask(0, res + mid)) r = mid - 1;
			else l = mid + 1;
		}
		res += (l - 1);
	}
	for (int i = S == 1; i <= 9; ++i) {
		if (ask(0, 10ll * (i + res))) return ask(1, i + res), 0;
	}
	ask(1, res);
	return 0;
}
/*
Y
Y
Y
N
N
N
Y
N
Y
N
*/