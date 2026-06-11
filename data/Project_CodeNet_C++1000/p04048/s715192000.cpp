//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

ll n, x;

ll f(ll a, ll b) {
	cerr << a << ' ' << b << endl;
	if (a % b == 0 || b % a == 0)
		return 2 * min(a, b) * (max(a, b) / min(a, b)) - min(a, b);
	if (a < b)
		return f(a, b % a) + 2 * a * (b / a);
	else
		return f(a % b, b) + 2 * b * (a / b);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	cout << f(x, n - x) + n << endl;
	return 0;
}
