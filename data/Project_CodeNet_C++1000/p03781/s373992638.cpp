#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#define lp(n) for (int i = 0; i < n; i++)
#define lop(n,i) for (int i = 0; i < n; i++)
#define INT_MAX 2147483647
#define LLINT_MAX 9223372036854775807
#define mod 1000000007
#define ll long long int
using namespace std;

int main() {
	int x, ans;
	int i = 0;
	cin >> x;
	while (true) {
		if ((i - 1)*i / 2 < x && x <= i*(i + 1) / 2) {
			ans = i;
			break;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}