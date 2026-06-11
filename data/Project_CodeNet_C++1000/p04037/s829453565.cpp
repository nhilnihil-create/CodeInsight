#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, arr[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());
	int id = -1;
	for (int i = 0; i < n; i++)
	{
		arr[i] -= i + 1;
		if (arr[i] >= 0)
		{
			id = i;
		}
	}
	int go = 0;
	for (int i = id + 1; i < n; i++)
	{
		if (arr[i] == (id - i))
		{
			go++;
		}
		else
		{
			break;
		}
	}
	if ((arr[id] | go) & 1)
	{
		cout << "First\n";
	}
	else
	{
		cout << "Second\n";
	}
	return 0;
}