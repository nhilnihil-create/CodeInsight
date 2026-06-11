#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int h, w;
	cin >> h >> w;
	char p[h+2][w+2];
	for (int i = 0; i < h + 2; i++)
	{
		for (int j = 0; j < w + 2; j++)
		{
			if (i == 0 || i == h + 1 || j == 0 || j == w + 1)		
				cout << "#";
			else
			{
				cin >> p[i][j];
				cout << p[i][j];
			}
		}
		cout << "\n";
	}
}

