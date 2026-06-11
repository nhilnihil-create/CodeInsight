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

const int N = 500 + 5;
int h, w, n, m;
int ans[N][N];
int sum = 0;

int main() 
{
	cin >> n >> m >> h >> w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i % h == h - 1 && j % w == w - 1)
			{
				ans[i][j] = (h * w - 1) * -3000 - 1;
			}
			else
			{
				ans[i][j] = 3000;
			}
			sum += ans[i][j];
		}
	}
	if (sum <= 0)
	{
		cout << "No";
		exit(0);
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}



	

}
