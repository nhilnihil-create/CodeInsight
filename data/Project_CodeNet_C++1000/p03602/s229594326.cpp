#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int n;
int a[N][N], b[N][N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]), b[i][j] = a[i][j];
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i) if(k != i)
			for(int j = 1; j <= n; ++j) if(k != i && i != j && k != j)
			{
				if(a[i][j] > a[i][k] + a[k][j]) 
				{
					puts("-1");
					return 0;
				}
				if(a[i][j] == a[i][k] + a[k][j]) b[i][j] = b[j][i] = 0;
			}
	long long ans = 0;			
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) ans += b[i][j];
	cout << ans / 2;	
	return 0;
}