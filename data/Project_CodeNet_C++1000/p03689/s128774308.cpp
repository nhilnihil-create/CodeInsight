#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10, base = 2500 + 1;
int a[N][N];
long long ps;
int main() {
	int n, m, nn, mm;
	cin >> n >> m >> nn >> mm;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			a[i][j] = base;
	int inf = -1 * base * (nn * mm - 1) - 1;
	for (int i = nn - 1; i < n; i += nn)
		for (int j = mm - 1; j < m; j += mm) 
			a[i][j] = inf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			ps += a[i][j];
	if (ps > 0) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				cout << a[i][j] << " ";
			cout << endl;
		}
	}
	else 
		cout << "No";
	return 0;
}	
