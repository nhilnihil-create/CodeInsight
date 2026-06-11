#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
//#define int long long
struct Point {
	int x, y;

	double dis(Point a, Point b) {
		double x = a.x - b.x;
		double y = a.y - b.y;
		return sqrt(x*x + y * y);
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	for (int i = 0; i < 4; i++)
	{
		cout << s[i];
	}
	cout << " ";
	for (int i = 4; i < 12; i++)
	{
		cout << s[i];
	}
	cout << endl;
	return 0;
}
