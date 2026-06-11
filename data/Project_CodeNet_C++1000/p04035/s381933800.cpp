//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

ll n, l, a[MAXN];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ind = 0;
	for (int i = 1; i < n; i++)
		if (a[i] + a[i + 1] >= l)
			ind = i;
	if (!ind)
		return cout << "Impossible" << endl, 0;
	cout << "Possible" << endl;
	for (int i = 1; i < ind; i++)
		cout << i << endl;
	for (int i = n - 1; i > ind; i--)
		cout << i << endl;
	cout << ind << endl;
	return 0;
}
