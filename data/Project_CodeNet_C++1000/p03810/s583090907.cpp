#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;
 
const int MAXN = 100005;
 
int n;
int a[MAXN];
 
bool check()
{
	for (int i = 1;i <= n;i++)
		if (a[i] == 1)
		{
			int sum = 0;
			for (int j = 1;j <= n;j++)
				sum ^= (a[j] - 1);
			return ~sum & 1;
		}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		cnt += (a[i] & 1);
	int step = ((n - cnt) & 1);
	if (cnt > 1 && !step)
		return 1;
	if (cnt >= 1 && step)
		return 0;
	for (int i = 1;i <= n;i++)
		if (a[i] & 1)
			a[i]--;
	int g = 0;
	for (int i = 1;i <= n;i++)
		g = __gcd(g,a[i]);
	for (int i = 1;i <= n;i++)
		a[i] /= g;
	return check() ^ 1;
}
 
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	if (n == 1)
	{
		puts((a[1] & 1) ? "Second" : "First");
		return 0;
	}
	puts(check() ? "Second" : "First");
	return 0;
}