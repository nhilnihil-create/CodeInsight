#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const int Maxn = 1000000 + 100, Mod = 1000000007;
LL N;
LL F[Maxn];
int main()
{
	scanf("%lld", &N);
	F[1] = N;
	F[2] = (N * N) % Mod;
	LL Sum = 0;
	for (int i = 3; i <= N; ++i)
	{
		F[i] = (F[i - 1] + Sum) % Mod;
		F[i] = (F[i] + ((N - 1) * (N - 1) % Mod)) % Mod;
		F[i] = (F[i] + N - i + 2) % Mod;
		Sum = (Sum + F[i - 2]) % Mod;
	}
	printf("%lld\n", F[N]);
	return 0;
}