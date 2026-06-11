#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>>stu(n, vector<ll>(2));
	vector<vector<ll>>che(m, vector<ll>(2));
	for (int i = 0; i < n; i++)cin >> stu.at(i).at(0) >> stu.at(i).at(1);
	for (int i = 0; i < m; i++)cin >> che.at(i).at(0) >> che.at(i).at(1);
	for (int i = 0; i < n; i++) {
		ll dis = 1000000000000000000;
		ll pos = -1;
		for (int j = 0; j < m; j++) {
			ll md = abs(stu.at(i).at(0) - che.at(j).at(0)) + abs(stu.at(i).at(1) - che.at(j).at(1));
			if (md < dis) {
				dis = md;
				pos = j;
			}
		}
		cout << pos+1 << endl;
	}
}