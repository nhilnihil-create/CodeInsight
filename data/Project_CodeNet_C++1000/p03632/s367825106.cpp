#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int res = min(b, d) - max(a, c);

	cout << ((res > 0) ? res : 0) << '\n';
	return 0;
}
