#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int n;
int a[MAXN];

void read()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

bool on_bound(int x, int y) { return a[x] <= y; }

void solve()
{
	sort(a, a + n);
	reverse(a, a + n);

	int x = 0, y = 0;
	while(true)
	{
		if(on_bound(x + 1, y + 1)) break;
		x++, y++;
	}

	int up_parity = (a[x] - y) & 1;
	int right_parity = 0;

	while(!on_bound(x, y)) x++, right_parity ^= 1; 

	if(up_parity == 1 && right_parity == 1) cout << "Second" << endl;
	else cout << "First" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

