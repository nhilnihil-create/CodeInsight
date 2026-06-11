#include <bits/stdc++.h>


using namespace std;


const int MAXN = 200 * 1000 + 132;




int n, x, a[2][5] = {-1, 0, 1, -3, -2, 1, 0, -1, 3, 2};
bool mark[MAXN];

int main() {
	cin >> n >> x;
	if (n == 1)
		return cout << "Yes\n" << x, 0;
	if ((x == 1) || (x == ((n << 1) - 1)))
		return cout << "No", 0;
	cout << "Yes\n";
	if (x == n) {
		for (int i = 1; i <= ((n << 1) - 1); i++)
			cout << i << ' ';
		return 0;	
	}
	if (x < n) {
		for (auto i : a[1])
			mark[x + i] = true;
		int p = 1;
		for (int i = 1; i <= ((n << 1) - 1); )
			if (abs(p - n) > 2) {
				if (!mark[i])
					cout << i << ' ', p++;
				i++;
			}
			else
				cout << x + a[1][p - n + 2] << ' ', p++;
		return 0;
	}
	for (auto i : a[0])
		mark[x + i] = true;
	int p = 1;
	for (int i = 1; i <= ((n << 1) - 1); )
		if (abs(p - n) > 2) {
			if (!mark[i])
				cout << i << ' ', p++;
			i++;
		}
		else
			cout << x + a[0][p - n + 2] << ' ', p++;
	return 0;
}