#include<cstdio>
using namespace std;
int a[100010];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int dap = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == i) {
			if (a[i + 1] == i + 1)
				i++;
			dap++;
		}
	}
	printf("%d", dap);
}