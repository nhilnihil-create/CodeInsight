#include <iostream>
#include <map>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	map<int, long long> mp;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mp[a] += b;
	}
	int ans;
	for (auto e : mp) {
		if (e.second >= k) {
          ans = e.first;
          break;
        }
		else k -= e.second;
	}
	cout << ans << endl;
	return 0;
}
