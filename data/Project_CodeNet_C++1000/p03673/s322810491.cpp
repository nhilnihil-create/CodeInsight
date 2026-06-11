#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[200005];
int main() {
	int n;
	cin >> n;
	deque<ll>ans;
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 0) {
				ans.push_back(a[i]);
			}
			else {
				ans.push_front(a[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 1) {
				ans.push_back(a[i]);
			}
			else {
				ans.push_front(a[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
