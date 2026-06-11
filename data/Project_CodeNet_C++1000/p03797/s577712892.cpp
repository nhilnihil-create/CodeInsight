/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long n, m;
	cin >> n >> m;

	cout << min(n, m / 2ll) + (m - 2ll * min(n, m / 2ll)) / 4ll << "\n";

	return 0;
}