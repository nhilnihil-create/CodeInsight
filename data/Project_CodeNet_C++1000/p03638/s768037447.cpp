#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[105][105];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int h, w, n;
	cin >> h >> w;
	int i = 1, j = 1;
	cin >> n;
	for(int c = 1; c <= n; c++)
	{
		int a;
		cin >> a;
		while(a--)
		{
			arr[i][j] = c;
			if(i & 1)
			{
				if(j == w)
					i++;
				else
					j++;
			}
			else
			{
				if(j == 1)
					i++;
				else
					j--;
			}
		}
	}
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
