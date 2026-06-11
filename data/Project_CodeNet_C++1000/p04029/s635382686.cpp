#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define space ' '
typedef long long ll;
typedef long double ld;
const long double PI = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	ll n;
	cin >> n;
	ll ans = 0;
	while (n > 0) {
        ans += n;
        --n;
	}
	cout << ans << endl;

    return 0;
}
