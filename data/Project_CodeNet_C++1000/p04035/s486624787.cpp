#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define N 100005
int n, l, a[N], x;
signed main()
{
	scanf("%d", &n), scanf("%d", &l);
	for(int i= 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i= 1; i < n; i++)
		if(a[i] + a[i + 1] >= l)
		{
			x= i;
			break;
		}
	if(x == 0)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for(int i= 1; i < x; i++) printf("%d\n", i);
	for(int i= n - 1; i > x; i--) printf("%d\n", i);
	printf("%d\n", x);
}