#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;

int N, a[100], cnt[101];
bool f;

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	sort(a, a + N);
	f = true;
	if (a[0] == a[1]) {
		if (cnt[a[0]] >= 3)f = false;
		if (a[N - 1] != a[0] * 2 - 1)f = false;
		for (int i = a[0] + 1; i <= a[N - 1]; ++i)
			if (cnt[i] <= 1)f = false;
	}
	else {
		if (a[N - 1] != a[0] * 2)f = false;
		for (int i = a[0] + 1; i <= a[N - 1]; ++i)
			if (cnt[i] <= 1)f = false;
	}
	if (f)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}