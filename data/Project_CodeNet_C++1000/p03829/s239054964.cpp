#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010, M = 2 * N;

int n, a, b;
int s[N];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i ++ ) scanf("%d", s + i);
	sort(s + 1, s + 1 + n);
	
	LL res = 0;
	for (int i = 1; i < n; i ++ )
	{
		int d = s[i + 1] - s[i];
		if ((LL)d * a >= (LL)b) res += b;
		else res += (LL)d * a;
	}
	printf("%lld\n", res);
    return 0;
}
