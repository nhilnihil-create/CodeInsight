//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, a[MAXN], nx, ny, x = 1, y;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int ind = 1;
	for (int i = 2; i <= n + 1; i++, nx++, ny++)
		if (a[i] <= nx + 1) {
			ind = i;
			break;
		}
	for (int i = ind; i <= n; i++)
		if (a[i] > nx)
			x++;
	y = a[ind - 1] - ny;
	cerr << "# " << ind << ' ' << x << ' ' << y << endl;
	if (x % 2 && y % 2)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
	return 0;
}
