#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';
#define rep(i, begin, end) \
	for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

string invert(string dir)
{
	string idir = "";
	for (char i : dir)
	{
		if (i == 'U')
			idir += "D";
		if (i == 'D')
			idir += "U";
		if (i == 'L')
			idir += "R";
		if (i == 'R')
			idir += "L";
	}
	return idir;
}

void solve()
{
	int xi, yi, xf, yf;
	cin >> xi >> yi >> xf >> yf;
	string dir1 = "";
	// at source
	if (yi > yf)
	{
		int d = yi - yf;
		while (d--)
			dir1 += "D";
	}
	else
	{
		int d = yf - yi;
		while (d--)
			dir1 += "U";
	}
	// at corner
	if (xi > xf)
	{
		int d = xi - xf;
		while (d--)
			dir1 += "L";
	}
	else
	{
		int d = xf - xi;
		while (d--)
			dir1 += "R";
	}
	// we are at the point
	dir1 += invert(dir1);
	string dir2 = "";
	// back to source
	if (xi > xf)
	{
		dir2 += "R";
	}
	else
	{
		dir2 += "L";
	}
	// shifted source
	if (yi > yf)
	{
		int d = yi - yf;
		while (d--)
			dir2 += "D";
		dir2 += "D";
	}
	else
	{
		int d = yf - yi;
		while (d--)
			dir2 += "U";
		dir2 += "U";
	}
	// we are at corner
	if (xi > xf)
	{
		int d = xi - xf;
		dir2 += "L";
		while (d--)
			dir2 += "L";
	}
	else
	{
		int d = xf - xi;
		dir2 += "R";
		while (d--)
			dir2 += "R";
	}
	// we are above the point
	if (yi > yf)
	{
		dir2 += "U";
	}
	else
	{
		dir2 += "D";
	}
	dir2 += invert(dir2);
	cout << dir1 + dir2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "\n\n~" << 500 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}