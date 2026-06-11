#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 300;
int a[MAXN + 1][MAXN + 1];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	bool valid = true;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int d = 2E9 + 5;
			for (int k = 1; k <= n; k++)
			{
				if (k == i || k == j)
					continue;
				d = min(d, a[i][k] + a[k][j]);
			}
			if (d < a[i][j])
				valid = false;
			else if (d > a[i][j])
				ans += a[i][j];
		}
	}
	cout << (valid ? ans : -1) << endl;

	return 0;
}