//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>

using namespace std;

const int N = 2e5 + 5;
int a[N];
int n;
int h;

bool isval(int x)
{
	bool mark[N];
	for (int i = 0; i < n; i++)
	{
		mark[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x)
		{
			mark[i] = true;
		}
	}
	int md = n / 2;
	if (mark[md] == mark[md + 1] || mark[md] == mark[md + 1])
	{
		if (mark[md] == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (mark[i] == mark[i + 1])
		{
			check = false;
		}
	}
	if (check)
	{
		if (mark[md] && h % 2 == 1)
		{
			return true;
		}
		if (mark[md] && h % 2 == 0)
		{
			return false;
		}
		if (!mark[md] && h % 2 == 0)
		{
			return true;
		}
		if (!mark[md] && h % 2 == 1)
		{
			return false;
		}
	}
	for (int i = md, j = md; i < n && j >= 0; i++, j--)
	{
		if (mark[i] == mark[i + 1])
		{
			if (mark[i] == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (mark[j] == mark[j - 1])
		{
			if (mark[j] == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int search()
{
	int up = n + 1;
	int down = -1;
	while (up - down > 1)
	{
		int md = (up + down) / 2;
		if (isval(md))
		{
			down = md;
		}
		else
		{
			up = md;
		}
	}
	return down;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		cin >> a[i];
	}
	h = n;
	n = 2 * n - 1;
	cout << search();

}

	
            


