#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	int w, h, n; cin >> w >> h >> n;
	int Xs = 0;
	int Xe = w;
	int Ys = 0;
	int Ye = h;
	rep(i, n)
	{
		int x,y,a;
		cin >> x >> y >> a;
		if (a == 1)
		{
			if (Xs < x)
			{
				// if (Xs < Xe)
					Xs = x;
				// else
				// 	Xs = Xe;
			}
		}
		if (a == 2)
		{
			if (Xe > x)
			{
				// if (Xe > Xs)
					Xe = x;
				// else
				// 	Xe = Xs;
			}
		}
		if (a == 3)
		{
			if (Ys < y)
			{
				// if (Ys < Ye)
					Ys = y;
				// else
				// 	Ys = Ye;
			}
		}
		if (a == 4)
		{
			if (Ye > y)
			{
				// if (Ye > Ys)
					Ye = y;
				// else
				// 	Ye = Ys;
			}
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
