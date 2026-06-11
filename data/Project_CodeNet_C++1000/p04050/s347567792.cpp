//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	int n, m;
	cin >> n >> m;
	vector < int > a(m);
	for (int i = 0; i < m; i++)
	{	
		cin >> a[i];
	}
	//~solve
	if (m == 1)
	{	
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << endl;
		if (a[0] == 1)
			cout << 1 << endl << 1 << endl;
		else
			cout << 2 << endl << a[0] - 1 <<  ' ' << 1 << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += (a[i] & 1);
	}
	if (cnt > 2)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 1; i < m - 1; i++)
	{
		if (a[i] & 1)
		{
			if (a[0] & 1)
				swap(a[m - 1], a[i]);
			else
				swap(a[0], a[i]);
		}
	}
	vector < int > b;
	b.pb(a[0] + 1);
	for (int i = 1; i < m - 1; i++)
		b.pb(a[i]);
	if (a[m - 1] != 1)
		b.pb(a[m - 1] - 1);
	//~result
	for (int i = 0; i < m; i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << (int)b.size() << endl;
	for (int i = 0; i < (int)b.size(); i++)
		cout << b[i] << ' ';
	cout << endl;	

	return 0;
}

