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
using namespace std;

int N;
bool IsY()
{
	char ch;
	cin >> ch;
	return ch == 'Y';
}

void Ans(int n)
{
	cout << "! " << n << endl;
	exit(0);
}

signed main()
{
	int a = 1000000000;
	int keta = 0;
	for (int k = 0; k < 9; k++)
	{
		cout << "? " << a << endl;
		if (IsY())
		{
			keta = 9 - k;
			break;
		}
		a /= 10;
	}
	if (keta == 9)
	{
		int b = 200000000;
		keta = 0;
		for (int k = 0; k < 9; k++)
		{
			cout << "? " << b << endl;
			if (!IsY())
			{
				keta = 9 - k;
				break;
			}
			b /= 10;
		}
	}

	int max = (int)pow(10, keta + 1) - 1;
	int min = (int)pow(10, keta);

	while (true)
	{
		int n = (max - min) / 2 + min;

		cout << "? " << (n * 10) << endl;
		if (IsY())
		{
			max = n;
		}
		else
		{
			min = n;
		}

		if (max - min <= 1)
		{
			cout << "? " << (min * 10) << endl;
			if (IsY())
			{
				Ans(min);
			}
			else
			{
				Ans(max);
			}
			break;
		}
	}
}