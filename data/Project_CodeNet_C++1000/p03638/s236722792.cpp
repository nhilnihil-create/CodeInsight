#include <bits/stdc++.h>
using namespace std;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };



int main() {
	fastIO;
	int h, w, n, x;
	cin >> h >> w >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	int grid[h][w];

	int curr = 0;
	for (int i = 0; i < h; i++) {
		if (i&1) {
			for (int j = w-1; j >= 0; j--) {
				grid[i][j] = curr+1;
				v[curr]--;
				if (v[curr] == 0)
					curr++;
			}
		}
		else {
			for (int j = 0; j < w; j++) {
				grid[i][j] = curr+1;
				v[curr]--;
				if (v[curr] == 0)
					curr++;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}






}
