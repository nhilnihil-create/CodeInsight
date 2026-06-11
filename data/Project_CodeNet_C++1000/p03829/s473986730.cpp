#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	ll sum = 0;
	for (int i = 1; i < n; i++)
		sum += min(b, a * (x[i] - x[i - 1]));
	cout << sum << endl;
	return 0;
}