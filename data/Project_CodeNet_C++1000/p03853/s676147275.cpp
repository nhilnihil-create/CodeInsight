#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)
const int INF = 1001001001;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> pic(h, vector<char>(w));
	rep(i, h) {
		rep(j, w) cin >> pic[i][j];
	}
	rep(i, 2 * h) {
		for (char c : pic[i / 2]) cout << c;
		cout << endl;
	}
 	return 0;
}