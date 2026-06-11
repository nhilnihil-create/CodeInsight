#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

int N, K;
int A[100000];
int B[100000];

int msb(int n)
{
	if (n == 0) return 0;

	int keta = 0;
	while (n > 0)
	{
		keta++;
		n >>= 1;
	}
	return 1 << (keta - 1);
}

signed main()
{
	cin >> N >> K;
	REP(i, N) cin >> A[i] >> B[i];

	int cost = 0;
	REP(i, N)
	{
		if ((K & A[i]) == A[i])
		{
			cost += B[i];
		}
	}
	int max = cost;

	if (K > 0)
	{
		int kk = msb(K);
		while (true)
		{
			int n = kk - 1;

			cost = 0;
			REP(i, N)
			{
				if ((n & A[i]) == A[i])
				{
					cost += B[i];
				}
			}
			max = MAX(max, cost);

			int m = msb(K - kk);
			kk += m;
			if (m == 0)
			{
				break;
			}
		}
	}

	cout << max;
}