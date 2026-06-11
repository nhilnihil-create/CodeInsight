#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int asc(const void *a, const void *b) {
	long *A = (long *)a;
	long *B = (long *)b;
	if (*A > *B) return 1;
	if (*A < *B) return -1;
	return 0;
}

int main()
{
	long n[3];
	long even = 0;
	long d;
	long sum = 1;
	rep (i , 3)
	{
		cin >> n[i];
		if (n[i] % 2 == 0)
		{
			cout << 0 << endl; return 0;
		}
		sum *= n[i];
	}
	qsort(n, sizeof (n) / sizeof (*n) , sizeof (*n), asc);
	long r = n[0] * n[1];
	long i = 0;
	long min = sum;
	int red;
	while (i < n[2])
	{
		// cout << r << '*' << i <<endl;
		if (labs((r * i) - (sum / 2)) < min)
		{
			min = labs((r * i) - (sum / 2));
			red = r * i;
		}
		i++;
	}
	long blue = sum - red;
	cout << r << endl;
	return (0);
}
