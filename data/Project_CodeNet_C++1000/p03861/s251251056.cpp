#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
	ll a, b, x;
	cin >> a >> b >> x;

	cout << ((a == 0) ? (b / x + 1) : (b / x - (a - 1) / x)) << '\n';
	return 0;
}
