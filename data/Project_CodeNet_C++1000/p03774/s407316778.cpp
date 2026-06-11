#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 7;
int lst[Max][2], ls[Max][2];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &lst[i][0],&lst[i][1]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &ls[i][0], &ls[i][1]);
	}
	for (int i = 1; i <= n; i++)
	{
		int res = 1e9,d;
		for (int j = 1; j <= m; j++)
		{
			if (abs(lst[i][0] - ls[j][0]) + abs(lst[i][1] - ls[j][1]) < res)
			{
				res = abs(lst[i][0] - ls[j][0]) + abs(lst[i][1] - ls[j][1]);
				d = j;
			}
		}
		cout << d << endl;
	}
}