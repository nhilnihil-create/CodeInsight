#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
int maxi, mini;

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	mini = a[0];
	maxi = a[n - 1];
	if (maxi - mini > 1)
	{
		cout << "No";
		exit(0);
	}
	if (maxi == mini && (n >= maxi * 2 || maxi == n - 1))
	{
		cout << "Yes";
		exit(0);
	}
	if (maxi == mini)
	{
		cout << "No";
		exit(0);
	}
	int cnt = 0;
	for (int i = 0 ; i < n; i++)
	{
		if (a[i] == mini)
		{
			cnt++;
		}
	}
	if (cnt > mini)
	{
		cout << "No";
		exit(0);
	}
	maxi = maxi - cnt;
	if (maxi == 0 && n - cnt > 0)
	{
		cout << "No";
		exit(0);
	}
	if ((n - cnt) >= maxi * 2)
	{
		cout << "Yes";
		exit(0);
	}
	else
	{
		cout << "No";
		exit(0);
	}

}
