#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	long long int n,a,b;
	long long int ans = 0;
	cin >> n>>a>>b;
	vector<long long int> d(n);
	for (int i = 0; i < n; i++)cin >> d.at(i);

	for (int i = 0; i < n - 1; i++) {
		if (a * (d.at(i + 1) - d.at(i)) > b)ans += b;
		else ans += a * (d.at(i + 1) - d.at(i));
	}
	cout << ans << endl;
	return 0;
}