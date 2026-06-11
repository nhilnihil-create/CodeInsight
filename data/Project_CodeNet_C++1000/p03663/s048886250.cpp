#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;


ll Pow10[11];
char c;

int main() {
	Pow10[0] = 1;
	for (int i = 1; i < 11; ++i) {
		Pow10[i] = Pow10[i - 1] * 10;
	}
	for (int i = 1; i < 10; ++i) {
		cout << '?' << sp << Pow10[i] << endl;
		cin >> c;
		if (c == 'N') {
			ll l = Pow10[i - 1];
			ll r = Pow10[i] - 1;
			while (l + 1 != r) {
				cout << '?' << sp << (l + r) / 2 << 0 << endl;
				cin >> c;
				if (c == 'Y') {
					r = (l + r) / 2;
				}
				else {
					l = (l + r) / 2;
				}
			}
			cout << '!' << sp << r << endl;
			return 0;
		}
	}
	for (int i = 1; i < 11; ++i) {
		cout << '?' << sp << Pow10[i] - 1 << endl;
		cin >> c;
		if (c == 'Y') {
			cout << '!' << sp << Pow10[i - 1] << endl;
			return 0;
		}
	}
}