#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);

	bool firstwin = false;

	for (bool first = true;; first ^= true)
	{
		int even = 0, one = 0;
		for (int i = 0; i < n; i++)
		{
			if (dat[i] % 2 == 0) even++;
			else if (dat[i] == 1) one++;
		}

		if (one)
		{
			if (even % 2) firstwin = first;
			else firstwin = !first;
			break;
		}

		if (even % 2)
		{
			firstwin = first;
			break;
		}

		if (even != n - 1)
		{
			firstwin = !first;
			break;
		}

		int g = 0;

		for (int i = 0; i < n; i++)
		{
			if (dat[i] % 2) --dat[i];
			g = gcd(dat[i], g);
		}

		for (int i = 0; i < n; i++) dat[i] /= g;
	}

	if (firstwin) printf("First\n");
	else printf("Second\n");
}