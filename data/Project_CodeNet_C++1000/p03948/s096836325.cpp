#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int v[100005];
int t[100005];
int main(void)
{
	int N, T;
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++)
		scanf("%d", &v[i]);
	int max = v[N];
	int MAX = 0;
	for (int i = N-1; i >= 1; i--)
	{
		t[i] = max - v[i];
		if (t[i] > MAX)MAX = t[i];
		if (v[i] > max)max = v[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		if (t[i] == MAX)
			ans++;
	printf("%d\n", ans);
	return 0;
}