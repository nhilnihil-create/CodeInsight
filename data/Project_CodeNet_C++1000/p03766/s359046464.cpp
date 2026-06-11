#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 1e6 + 10;
const int Mod = 1e9 + 7;

void add(int &x, int y){
	x += y;
	if(x >= Mod) x -= Mod;
}

int mul(long long x, int y){
	return x * y % Mod;
}

int n, f[N];

int main(){
	scanf("%d", &n);

	f[0] = 1;
	int sum = 0;
	For(i, 1, n){
		f[i] = sum;
		add(f[i], f[i - 1]);
		if(i > 1) add(sum, f[i - 2]);
	}

	int ans = f[n];
	add(ans, mul(f[n - 1], n - 1));
	add(ans, mul(sum, mul(n - 1, n - 1)));
	For(i, 0, n - 2) add(ans, mul(f[i], i + 1));

	printf("%d\n", ans);

	return 0;
}