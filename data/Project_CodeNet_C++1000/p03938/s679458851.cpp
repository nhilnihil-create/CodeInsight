#include <bits/stdc++.h>


using namespace std;


const int MAXN = 100 * 1000 + 13;




int n, a[MAXN], p[MAXN], b[MAXN];



int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--, a[i] = (i + 1) * 2 * n, b[i] = (n - i) * 2 * n;
	for (int i = 0; i < n; i++)
		a[p[i]] -= 2 * n - i - 1;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	return 0;
}