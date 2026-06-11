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

ll n, a, b, mn, mx, h[100000], cnt;

int main() {
	cin >> n >> a >> b;
	mx = 0;
	mn = intmax;
	lp(n) {
		cin >> h[i];
		mx = max(mx, h[i]);
		mn = min(mn, h[i]);
	}
	mn = mn / a;
	mx = mx / b + 1;
	
	while (mn + 1 != mx) {
		cnt = 0;
		lp(n) {
			if (h[i] - ((mn + mx) / 2)*b > 0) {
				cnt += (h[i] - ((mn + mx) / 2)*b - 1) / (a - b) + 1;
			}
		}
		if (cnt <= (mn + mx) / 2)
			mx = (mn + mx) / 2;
		else mn = (mn + mx) / 2;
	}
	cout << mx << endl;
	return 0;
}