#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
string yes = "Yes\n";
string no = "No\n";

int  main()
{
	int x,y; cin >> x >> y;
	char g[13];
	rep1(i, 12)
	{
		if (i == 2)
			g[i] = 'c';
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			g[i] = 'b';
		else
			g[i] = 'a';
	}
	if (g[x] == g[y])
		cout << yes;
	else
		cout << no;
	return (0);
}