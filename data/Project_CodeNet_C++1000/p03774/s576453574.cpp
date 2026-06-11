#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n, m;
	cin >> n >> m;
	P student[55];
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		student[i]=make_pair(a, b);
	}
	P point[55];
	for (int i = 0; i < m; i++) {
		int c, d;
		cin >> c >> d;
		point[i] = make_pair(c, d);
	}
	for (int i = 0; i < n; i++) {
		int anspoint = 100;
		ll ans = inf;
		for (int j = 0; j < m; j++) {
			ll x = abs(student[i].first - point[j].first) + abs(student[i].second - point[j].second);
			
			if (ans > x) {
				ans = x;
				anspoint = j+1;
			}
		}
		cout << anspoint << endl;
	}
	return 0;
}