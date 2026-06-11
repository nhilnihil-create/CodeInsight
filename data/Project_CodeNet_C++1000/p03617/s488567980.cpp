#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll q, h, s, d, n; cin >> q >> h >> s >> d >> n;
	s = min({s, h * 2, q * 4});
	cout << min(s * n, (n / 2) * d + (n % 2) * s) << endl;
}