#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

ll n, m, x, x2, y, y2, cntx, cnty, ans;

int main() {
	cin >> n >> m;
	cntx = cnty = 0;
	cin >> x;
	lp(n - 1) {
		cin >> x2;
		cntx += (x2 - x) * (i + 1)*(n - 1 - i);
		x = x2;
	}
	cin >> y;
	lp(m-1) {
		cin >> y2;
		cnty += (y2 - y)*(i + 1)*(m - 1 - i);
		y = y2;
	}
	cout << (cntx%mod)*(cnty%mod) % mod << endl;
	return 0;
}
