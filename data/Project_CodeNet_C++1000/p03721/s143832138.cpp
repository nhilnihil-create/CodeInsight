#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	cin >> n;
	ll k;
	vector<P>p(n);
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p.begin(), p.end());
	ll count = 0;
	for (int i = 0; i < n; i++) {
		count += p[i].second;
		if (count >= k) {
			cout << p[i].first << endl;
			return 0;
		}
	}
	return 0;
}
