#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 1000;

int n, a[MAXN];

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

bool check()
{
	// cerr << "!" << endl;
	if(n == 1 && a[1] == 1)
		return false;
	int even = 0, odd = 0;
	for(int i = 1; i <= n; i++)
		(a[i] & 1 ? odd : even)++;
	if(even & 1)
		return true;
	if((~even & 1) && odd >= 2)
		return false;
	int g = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & 1)
		{
			if(a[i] == 1) return false;
			else a[i]--;
		}
		g = gcd(g, a[i]);
	}
	// cerr << g << endl;
	for(int i = 1; i <= n; i++)
		a[i] /= g;
	return !check();
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	bool ans = check();
	cout << (ans ? "First" : "Second") << endl;


	return 0;
}
