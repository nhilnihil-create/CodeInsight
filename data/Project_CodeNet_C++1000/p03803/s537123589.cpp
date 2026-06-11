#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	if (n == 1) n = 14;
	if (m == 1) m = 14;
	if (n > m) cout << "Alice\n";
	if (m > n) cout << "Bob\n";
	if (n == m) cout << "Draw\n";
	return 0;
}
