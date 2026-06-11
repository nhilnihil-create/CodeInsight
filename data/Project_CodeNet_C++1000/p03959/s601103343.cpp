#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	int t[100000], a[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l[100000], r[100000];
	l[0] = t[0];
	r[0] = t[0];
	for (int i = 1; i < n; i++)
	{
		if (t[i] > t[i - 1])
		{
			l[i] = t[i];
			r[i] = t[i];
		}
		else
		{
			l[i] = 1;
			r[i] = r[i - 1];
		}
	}
	l[n - 1] = max(l[n - 1], a[n - 1]);
	r[n - 1] = min(r[n - 1], a[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] > a[i + 1])
		{
			l[i] = max(l[i], a[i]);
			r[i] = min(r[i], a[i]);
		}
		else
		{
			l[i] = max(l[i], 1);
			r[i] = min(r[i], r[i + 1]);
		}
	}
	long long int ans = 1;
	for (int i = 0; i < n; i++)
	{
		// cout << l[i] << " " << r[i] << endl;
		ans = (ans * (max(0, r[i] - l[i] + 1))) % mod;
	}
	cout << ans << endl;
}