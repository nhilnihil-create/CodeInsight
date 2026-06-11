#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll inf = 1000000000;
typedef pair<ll, ll> P;
int a[100005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n-1; i++) {
		if (a[i] == 0 && a[i] == a[i + 1]) {
			cout << "0" << endl;
			return 0;
		}
		if (i != n - 1 && a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			cout << "0" << endl;
			return 0;
		}
	}
	ll sum = 1;
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i + 1]) {
			sum = (sum * 2)%1000000007;
		}
	}
	cout << sum%1000000007<< endl;
	return 0;
}
