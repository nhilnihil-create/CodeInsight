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
const int mod = 1000000007, mod998 = 998244353;

int N, A, t;
ll res;

int main() {
	cin >> N;
	cin >> res;
	--N;
	--res;
	t = 2;
	while (N--) {
		cin >> A;
		res += (A - 1) / t;
		if (A == t)++t;
	}
	cout << res << endl;
	return 0;
}