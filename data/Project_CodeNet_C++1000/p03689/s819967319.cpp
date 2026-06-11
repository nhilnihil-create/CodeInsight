#include <bits/stdc++.h>
using namespace std;
const int N = 504;
int a[N][N];
int H, W, h, w;
int main()
{
	cin >> H >> W >> h >> w;

	if(H % h == 0 && W % w == 0)
		return cout << "No", 0;

	
	cout << "Yes\n";

	for(int i = 0; i < H; i++)
	{
		for(int j = 0;j < W;j++)
		{
			if(H % h != 0)
			{
				if(i % h == 0)
					a[i][j] = 1000 * (h - 1) - 1;
				else
					a[i][j] = -1000;
			}

			else
			{
				if(j % w == 0)
					a[i][j] = 1000 * (w - 1) - 1;
				else
					a[i][j] = -1000;
			}
			
		}
	}

	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}