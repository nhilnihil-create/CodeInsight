#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100055;

int A[MAXN], O[MAXN];

ll Ans[MAXN];
int N;

int main() {
	ios::sync_with_stdio(false);
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		Ans[1] += A[i];
	}

	iota(O, O+N+1, 0); sort(O+1, O+N+1, [&](int a, int b) {
		return A[a] != A[b] ? A[a] > A[b] : a < b;
	});
	
	for(int s = 1, e, i = N, t; s <= N; s = e) {
		t = O[s]; if(t < i) i = t; if(1 == i) break;
		for(e = s+1; e <= N && A[O[e]] == A[i]; e++);
		Ans[i] += ll(A[i] - A[O[e]]) * (e-1);
		A[i] = A[O[e]];
	}
	for(int i = 2; i <= N; i++) Ans[1] -= Ans[i];
	for(int i = 1; i <= N; i++) printf("%lld\n", Ans[i]);
	return 0;
}