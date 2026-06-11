#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
using namespace std;

lli small(lli a, lli b, lli c) {
	lli l = min(a, b); l = min(l, c);
	lli r = max(a, b); r = max(r, c);
	lli ans = r - l;
	return ans;
}

lli split(lli x, lli y) {
	lli m = 10000000000;
	lli A, B, C;
	rep(i, 1, x / 2 + 1) {
		A = i * y;
		B = (x - i)*(y / 2);
		C = (x - i)*(y - y / 2);
		m = min(m, small(A, B, C)); //cout << m << endl;
		lli j = x - i;
		A = i * y;
		B = j / 2 * y;
		C = (j - j / 2)*y;
		m = min(m, small(A, B, C));
	}

	return m;
}

int main(void)
{
	lli H, W; cin >> H >> W;
	if (H % 3 == 0 || W % 3 == 0)cout << 0 << endl;
	else {
		cout << min(split(H, W), split(W, H)) << endl;

	}

	return 0;
}
