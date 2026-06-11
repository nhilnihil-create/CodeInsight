#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

#define MOD (1000000007)
#define NONE (0)
#define VERT (1)
#define HORI (2)

int main()
{
	int N, pre = NONE, cur;
	ll ans = 0;
	string S1, S2;

	cin >> N >> S1 >> S2;

	rep(i, N) {
		if (S1[i] == S2[i]) cur = VERT;
		else {
			cur = HORI;
			i++;
		}

		if (pre == NONE && cur == HORI) ans = 6;
		else if (pre == NONE && cur == VERT) ans = 3;
		else if (pre == HORI && cur == HORI) ans = (ans * 3) % MOD;
		else if (pre == HORI && cur == VERT) ans = (ans * 1) % MOD;
		else if (pre == VERT && cur == HORI) ans = (ans * 2) % MOD;
		else if (pre == VERT && cur == VERT) ans = (ans * 2) % MOD;

		pre = cur;
	}

	cout << ans << endl;

	return 0;
}
