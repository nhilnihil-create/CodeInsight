#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
#define maxn  100500
#define inf 0x3f3f3f3f
int a[maxn];
int main()
{
	int ans = 0;
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int temp, maxx;
	temp = inf;
	maxx = -inf;
	for (int i = 1; i <= n; i++) {
		temp = min(temp, a[i]);
		maxx = max(maxx, a[i]-temp);
	}

	temp = inf;
	for (int i = 1; i <= n; i++) {
		temp = min(temp, a[i]);
		if (maxx == a[i]-temp)ans++;
	}
	printf("%d\n", ans);
}