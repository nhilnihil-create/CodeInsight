#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#define lp(n) for (int i = 0; i < n; i++)
#define lop(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define ll long long int
#define sp ' '
#define intmax 2147483647
#define intmin –2147483648
#define llmax 9223372036854775807
#define llmin -9223372036854775808
using namespace std;

int n;
ll a[200000], mn;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	ll g = gcd(x, y);
	return x / g * y;
}

int main(){
	cin >> n;
	lp(n) {
		cin >> a[i];
		if (i >= 1)
			a[i] += a[i - 1];
	}
	mn = llmax;

	lp(n-1) {
		mn = min(mn, abs(a[n - 1] - a[i] - a[i]));
	}
	cout << mn << endl;
	return 0;
}