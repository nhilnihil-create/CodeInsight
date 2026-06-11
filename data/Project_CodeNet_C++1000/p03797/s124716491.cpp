#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main()
{
	ll s, c;
	cin >> s >> c;

	if (c <= 2 * s) cout << c / 2 << endl;
	else cout << s + (c - 2 * s) / 4 << endl;
}