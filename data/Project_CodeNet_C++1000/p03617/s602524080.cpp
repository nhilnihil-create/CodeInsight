#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

typedef struct _data
{
	long Q;
	long q;
	double l;
} data;

// struct _data data;

int q_cmp(const void *a, const void *b)
{
	return ((struct _data*)a)->q - ((struct _data*)b)->q;
}

int main()
{
	struct _data set[4];
	rep(i ,4)
		cin >> set[i].Q;
	long n;
	cin >> n;
	// long double n = N;
	set[0].q = 4 * set[0].Q;
	set[1].q = 2 * set[1].Q;
	set[2].q = set[2].Q;
	set[3].q = 0.5 * set[3].Q;

	set[0].l = 0.25;
	set[1].l = 0.5;
	set[2].l = 1.0;
	set[3].l = 2.0;
	int size = sizeof(set) / sizeof(_data);
	qsort(set, size, sizeof(_data), q_cmp);
	long ans = 0;
	rep(i,4)
	{
		// cout << (set[i].q * n % set[i].Q) << endl;
		// if (set[i].q * n % set[i].Q == 0 )
		// {
		// 	// cout << set[i].q * n % set[i].q << endl;
		// 	ans += set[i].q * n;
		// 	break;
		// }
		if (n >= set[i].l)
		{
			// cout << (long)(n / set[i].l)<< endl;
			ans += (long)(n / set[i].l) * set[i].Q;
			n -= (long)(n / set[i].l) * set[i].l;
			// cout << n << endl;
		}
		if (n == 0)
		{
			break;
		}
		// cout << set[i].Q << "|" << set[i].l << "|" << set[i].q<< endl;
	}
	// cout << set[0].q << (set[0].q * (long)n) % set[0].Q << endl;
	cout << ans << endl;
	return (0);
}
