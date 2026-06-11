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
#define int long long
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

	int H, W;
	cin >> H >> W;
	int ai = 1;
	char ac = 'A';


	for (int i = 0; i < H; i++)
	{
		ac = 'A';
		for (int j = 0; j < W; j++)
		{
			string s;
			cin >> s;
			if (s == "snuke") {
				goto LAST;
			}
			ac++;
		}
		ai++;
	}
LAST:
	cout << ac << ai << endl;
	return 0;
}
