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

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	int last = 1,j = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] > a[i + 1] && (i + a[i]) % 2 == 0)
			j = i;
		if (a[i] > a[i + 1] && ((i + a[i]) % 2 == 1 || i == n))
		{
			if (last && j && last <= j && last <= a[last] && j >= a[j + 1] + 1)
			{
				cout << "Second" << endl;
				return 0;
			}
			last = i + 1;
		}
	}
	cout << "First" << endl;
	return 0;
}