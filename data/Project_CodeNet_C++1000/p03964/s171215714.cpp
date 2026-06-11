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

int T[1000];
int A[1000];

int main()
{
	int N;
	ll TS, AS, mul1, mul2;

	cin >> N;
	rep(i, N) cin >> T[i] >> A[i];

	TS = T[0];
	AS = A[0];

	repc(i, 1, N - 1) {
		mul1 = (TS - 1) / T[i] + 1;
		mul2 = (AS - 1) / A[i] + 1;
		TS = T[i] * max(mul1, mul2);
		AS = A[i] * max(mul1, mul2);
	}

	cout << TS + AS << endl;

	return 0;
}
