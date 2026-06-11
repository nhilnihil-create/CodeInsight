#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
typedef pair<li, li> PI;

PI a[100100];

int main(void)
{
	li n;
	cin >> n;
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	cout << a[n - 1].first + a[n - 1].second << endl;

	return 0;
}