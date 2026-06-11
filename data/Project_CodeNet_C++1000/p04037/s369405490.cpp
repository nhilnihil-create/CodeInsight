#include <bits/stdc++.h>
using namespace std;

const int MaxN(100003);
int A[MaxN];

int main()
{
	int n, ans = 0;
#ifdef zxp
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	sort(A + 1, A + 1 + n, greater<int> ());
	for(int i = 1; i <= n; i++)
		if(i + 1 > A[i + 1])
		{
			for(int j = i + 1; A[j] == i; j++)
				ans ^= 1;
			ans |= (A[i] - i) & 1;
			break;
		}
	puts(ans ? "First" : "Second");
	return 0;
}
