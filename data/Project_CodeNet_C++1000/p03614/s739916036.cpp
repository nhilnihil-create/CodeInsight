#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100000 + 100;
int A[Maxn], P[Maxn];
int N;
int main()
{
	scanf("%d", &N);
	int Sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		if (A[i] == i)P[i] = 1, ++ Sum;
	}
	if (Sum == 0)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i < N; ++i)
		if (P[i] && P[i + 1]) -- Sum, ++ i;
	cout<<Sum<<endl;
	return 0;
}