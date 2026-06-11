#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010, M = 10;

int n, h, w;
int a[N];
int g[N][N];

int main()
{
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for (int i = 0, k = 1; i < h; i ++ )
		if (i & 1)
		{
			for (int j = 0; j < w; j ++ )
			{
				g[i][j] = k;
				if ( -- a[k] == 0) k ++ ;
			}
		}
		else
		{
			for (int j = w - 1; j >= 0; j -- )
			{
				g[i][j] = k;
				if ( -- a[k] == 0) k ++ ;
			}
		}
	
	for (int i = 0; i < h; i ++ )
	{
		for (int j = 0; j < w; j ++ )
			cout << g[i][j] << ' ';
		puts("");
	}
    return 0;
}