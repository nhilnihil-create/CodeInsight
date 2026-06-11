#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void fuk() { puts("NO"); exit(0); }

const int MAXN = 100055;

ll A[MAXN], B[MAXN];

ll Sum, T;
int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		Sum += A[i];
	}
	T = ll(N) * (N+1) / 2;
	if(Sum % T) fuk();
	T = Sum / T;
	A[0] = A[N];
	for(int i = 1; i <= N; i++)
		B[i] = A[i] - A[i-1];
	for(int i = 1; i <= N; i++) B[i] -= T;
	Sum = 0;
	for(int i = 1; i <= N; i++) {
		if(0 < B[i]) fuk();
		B[i] = -B[i];
		if(B[i] % N) fuk();
		Sum += B[i] / N;
	}
	if(Sum != T) fuk();
	puts("YES");
	return 0;
}