#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
ll n, a[200010], ruiseki[200010];
ll sum, ans = 2000000000000000000;
int main() {
	cin >> n;
	cin >> a[0];
	sum = a[0];
	ruiseki[0] = a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		ruiseki[i] = ruiseki[i - 1] + a[i];
	}
	for (int i = 0; i < n - 1; i++)if (abs(ruiseki[i] - (sum - ruiseki[i])) < ans)ans = abs(ruiseki[i] - (sum - ruiseki[i]));
	cout << ans << endl;
	return 0;
}