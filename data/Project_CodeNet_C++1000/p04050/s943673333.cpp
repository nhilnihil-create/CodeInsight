#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 20, maxx = 102;

int a[maxx], n, m;
vector<int> fard;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) 
	{
		cin >> a[i];
		if (a[i] % 2) fard.push_back(i);
	}
//	sort(fard.begin(), fard.end());
	if (m == 1 && n == 1) return cout << 1 << endl << 1 << endl << 1 << endl, 0;
	if (m == 1) return cout << a[0] << endl << 2 << endl << a[0] - 1 << " " << 1 << endl, 0;
	if (fard.size() > 2) return cout << "Impossible" << endl, 0;
	if (fard.size())
		swap(a[m-1], a[fard[0]]);
	if (fard.size() > 1)
		swap(a[0], a[fard[1]]);
//	if (fard.size() == 2 && n == 2) return cout << a[0] << " " << a[1] << endl << 1 << endl << 2 << endl, 0;
//	if (a[0] == 1 && a[m-1] == 1) while (true) cout << 0 / 0 << endl;
//	if (a[0] == 1) swap(a[0], a[m-1]);
	for(int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl << (a[0] == 1 ? m - 1 : m) << endl;
	for(int i = 0; i < m; i++) 
	{
		if (!i)
		{
			if (a[i] != 1) cout << a[i] - 1 << " ";
		}
		else if (i == m-1) cout << a[i] + 1 << " ";
		else	cout << a[i] << " ";
	}
	cout << endl;
//	for(int i = 0; i < m; i++) cout << a[i] << " ";
//	cout << endl << 1 << endl << n << endl;
//	cout << "Impossible" << endl;
	return 0;
}