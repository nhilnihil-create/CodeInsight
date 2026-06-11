#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <utility>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef pair<ll, double> PD;
//ll mod = 1000000007;
//ll mod = 998244353;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<string>> a(h, vector<string>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
				return 0;
			}
		}
	}
}