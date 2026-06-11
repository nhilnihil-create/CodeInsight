#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,a,MAX;
int cnt[105];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		cnt[a]++;
		MAX = max(MAX,a);
	}
	for (int i = MAX;i >= (MAX + 1) / 2;i--)
	{
		int s = 2;
		if (i == (MAX + 1) / 2 && MAX % 2 == 0)
			s = 1;
		if (cnt[i] < s)
		{
			puts("Impossible");
			return 0;
		}
		cnt[i] -= s;
	}
	for (int i = 1;i <= MAX;i++)
		if (cnt[i] && i <= (MAX + 1) / 2)
		{
			puts("Impossible");
			return 0;
		}
	puts("Possible");
	return 0;
}