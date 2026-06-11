
// A - Grouping

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int x, y;
	cin >> x >> y;

	vector<int> grp1 = {1, 3, 5, 7, 8, 10, 12};
	vector<int> grp2 = {4, 6, 9, 11};
	vector<int> grp3 = {2};

	int x_grp, y_grp;

	if (count(grp1.begin(), grp1.end(), x) > 0) x_grp = 1;
	if (count(grp2.begin(), grp2.end(), x) > 0) x_grp = 2;
	if (count(grp3.begin(), grp3.end(), x) > 0) x_grp = 3;

	if (count(grp1.begin(), grp1.end(), y) > 0) y_grp = 1;
	if (count(grp2.begin(), grp2.end(), y) > 0) y_grp = 2;
	if (count(grp3.begin(), grp3.end(), y) > 0) y_grp = 3;

	string ans;

	if (x_grp == y_grp) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}