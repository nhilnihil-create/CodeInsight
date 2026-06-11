/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

bool solve(int *a, int n);
int gcd(int x, int y);

int main()
{
	int n, a[N];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (solve(a, n))
		cout << "First\n";
	else
		cout << "Second\n";	
}

bool solve(int *a, int n)
{
	int odd = 0, even = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2)
			++odd;
		else
			++even;
	}

	if (!even)
		return false;

	if (even % 2)
		return true;

	if (odd > 1)
		return false;

	int g = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2)
		{
			if (a[i] == 1)
				return false;
			--a[i];	
		}

		g = gcd(g, a[i]);
	}

	for (int i = 0; i < n; ++i)
		a[i] /= g;

	return !solve(a, n);
}

int gcd(int x, int y)
{
	if (!y)
		return x;

	return gcd(y, x % y);
}