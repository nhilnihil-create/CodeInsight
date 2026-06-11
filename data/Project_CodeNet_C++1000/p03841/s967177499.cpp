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

const int N = 505;

using namespace std;

int n, ans[N * N];
pair < int, int > a[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	cin >> n;
	forn(i, n)	
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	//~sort
	sort(a + 1, a + n + 1);
	set < int > st;
	forn(i, n * n)	
		st.insert(i);
	forn(i, n)
	{
		ans[a[i].first] = a[i].second;
		st.erase(a[i].first);
		forn(j, a[i].second - 1)
		{
			int x = *st.begin();
			if (x > a[i].first)
			{
				cout << "No" << endl;
				return 0;
			}
			ans[x] = a[i].second;
			st.erase(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i].second + 1; j <= n; j++)
		{
			int x = *st.begin();
			if (x < a[i].first)
            {
            	cout << "No" << endl;
            	return 0;
            }
            ans[x] = a[i].second;
            st.erase(x);
		}
	}
	cout << "Yes" << endl;
	forn(i, n * n)
		cout << ans[i] << ' ';
	return 0;
}

