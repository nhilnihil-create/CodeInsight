#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

intt n;

int main() {

	FAST;

	cin >> n;
	intt ans = n / 11 * 2;
	if (n % 11) ans ++;
	if ((n % 11) > 6) ans ++;
	cout << ans << '\n';
	return 0;
}