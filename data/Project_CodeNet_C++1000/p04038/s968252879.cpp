#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int P = 1e9 + 7;

const int MaxN = 2020;
int f[MaxN][MaxN];
int fac[MaxN*MaxN];
int inv[MaxN*MaxN];
int facInv[MaxN*MaxN];
int N, M, g;

int add(int x, int y) { x += y; return x >= P ? x - P : x; }
int mul(int x, int y) { return (int64)x*y%P; }
int c(int x, int y) { return mul(fac[x], mul(facInv[y], facInv[x - y])); }
void inc(int& x, int y) { x = add(x, y); }

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> N >> M;
	if (M == 1) return puts("1")&0;
	fac[0] = facInv[0] = 1,
	fac[1] = inv[1] = facInv[1] = 1;
	for (int i = 2;i < MaxN * MaxN; ++i) {
		fac[i] = mul(fac[i-1], i),
		inv[i] = mul((P-P/i), inv[P%i]),
		facInv[i] = mul(facInv[i-1], inv[i]);
	}
	
	g = 1;
	for (int i = 1;i <= N; ++i)
		f[i][0] = 1, g = mul(g, i);
	for (int i = 1;i <= N; ++i) {
		for (int j = 1;j <= i; ++j) {
			inc(f[i][j], f[i-1][j]);
			inc(f[i][j], mul(f[i][j-1], c(N*M - i - (j-1) * (M - 1) - 1, M - 2)));
		}
	}
	
	cout << mul(g, f[N][N]);
	return 0; 
}

/*
f[i][j] += f[i-1][j] + f[i][j-1] * c(N*M - i - (j-1) * (M-1) - 1, M-2)
*/