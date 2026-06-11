#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 2 * N;

int n, h[N];

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i ++ )
	{
		int x;
		scanf("%d", &x);
		h[x] ++ ;
	}
	
	int cnt = 0, res = 0;
	for (int i = 1; i < N; i ++ )
		if (h[i])
		{
			res ++ ;
			if (h[i] % 2 == 0) cnt ++ ;
		}
	
	if (cnt & 1) printf("%d\n", res - 1);
	else printf("%d\n", res);
    return 0;
}