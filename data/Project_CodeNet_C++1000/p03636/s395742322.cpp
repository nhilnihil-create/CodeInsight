
// B - i18n

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int n = s.size() - 2;

	cout << *s.begin() << n << *s.rbegin() << endl;

	return 0;
}