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

const int N = (int)1e5 + 228;

using namespace std;

int n, a[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	//~solve
	sort(a + 1, a + n + 1);
	int ptr = 1;
	while(ptr < n && a[n - ptr] >= ptr + 1)
		ptr++;
	if (a[n - ptr + 1] == ptr && (ptr == n || a[n - ptr + 1] > a[n - ptr]))
	{
		cout << "Second" << endl;
		return 0;
	}
	if (((a[n - ptr + 1] - ptr) & 1))
	{
		cout << "First" << endl;
		return 0;
	}
	if (ptr < n)
	{
		int cnt = ptr - a[n - ptr];
		for (int i = n - ptr; i >= 1; i--)
		{
			cnt++;
			if (i == 1 || a[i] > a[i - 1])
				break;
		}
		if ((cnt & 1))
		{
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;

	return 0;
}

