#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int  main()
{
	int w, h, n; cin >> w >> h >> n;
	int Xs = 0; int Xe = w;
	int Ys = 0; int Ye = h;
	rep(i, n)
	{
		int x,y,a;
		cin >> x >> y >> a;
		if (a == 1)
		{
			if (Xs < x)
				Xs = x;
		}
		if (a == 2)
		{
			if (Xe > x)
				Xe = x;
		}
		if (a == 3)
		{
			if (Ys < y)
				Ys = y;
		}
		if (a == 4)
		{
			if (Ye > y)
				Ye = y;
		}
	}
	int X = Xe - Xs;
	int Y = Ye - Ys;
	if (X < 0)
		X = 0;
	if (Y < 0)
		Y = 0;
	cout << X * Y << endl;
	return 0;
}
