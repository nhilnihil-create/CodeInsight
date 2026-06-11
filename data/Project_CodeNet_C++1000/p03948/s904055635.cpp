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

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;


int n, t, a, mn, mxdf, cnt, mncnt, mxcnt;

int main() {
	cin >> n >> t;
	mn = intmax;
	mxdf = 0;
	cnt = 0;
	lp(n) {
		cin >> a;
		mn = min(mn, a);
		if (a - mn > mxdf) {
			mxdf = a - mn;
			cnt = 1;
		}
		else if (a - mn == mxdf) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}