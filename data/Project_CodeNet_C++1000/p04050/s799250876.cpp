#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int A[MAXN], n, m;
vector<int> B;

int main() {
	scanf("%d%d", &n, &m);
	int odd = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", A + i);
		if (A[i] & 1) ++odd;
	}
	if (odd > 2) return puts("Impossible") * 0;
	if (m == 1) {
		if (A[1] > 1) B.push_back(A[1] - 1);
		B.push_back(1);
	} else {
		for (int i = 1; i <= m; i++)
			if (A[i] & 1) swap(A[i], A[1]);
		for (int i = 2; i <= m; i++)
			if (A[i] & 1) swap(A[m], A[i]);
		if (A[1] & 1) B.push_back(A[1] + 1);
		else B.push_back(1), B.push_back(A[1]);
		for (int i = 2; i < m; i++) B.push_back(A[i]);
		if (A[m] & 1) { if (A[m] > 1) B.push_back(A[m] - 1); }
		else { B.push_back(1); if (A[m] > 2) B.push_back(A[m] - 2); }
	}
	for (int i = 1; i <= m; i++) printf("%d ", A[i]);
	printf("\n%d\n", (int)B.size());
	for (int i : B) printf("%d ", i);
	return 0;
}