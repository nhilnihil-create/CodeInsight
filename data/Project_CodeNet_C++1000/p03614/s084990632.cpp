#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

main()
{
	int n;
	
	cin >> n;
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		c += (a[i] == i);
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == i && a[i + 1] == i + 1)
		{
			c--;
			i++;
		}
	}
	
	cout << c << endl;
}


