#include <cstdio>
int arr[305][305]; 
bool flg[305][305]; 
int main()
{
	// freopen("ARC083-D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", arr[i] + j); 
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					puts("-1"); 
					return 0; 
				}
				if (arr[i][k] + arr[k][j] == arr[i][j] && k != i && k != j)
					flg[i][j] = true; 
			}
		}
	}
	long long ans = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (!flg[i][j])
				ans += arr[i][j]; 
		}
	}
	printf("%lld\n", ans);
	return 0; 
}
