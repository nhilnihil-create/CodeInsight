#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = deque<int>;
using db = double;
#define pb push_back
#define pf push_front

ll n;

vi a, b;
int t;

void cal(ll n) {
	if (n == 0)
		return;
	if (n % 2 == 1) {
		cal(n / 2);
		++t;
		a.pb(t);
		b.pb(t);
	} else {
		cal(n - 1);
		++t;
		a.pf(t);
		b.pb(t);
	}
}

int main() {
	cin >> n;
	
	cal(n);
	
	vi s = a;
	for (auto i : b) s.pb(i);
	
	cout << s.size() << endl;
	for (auto i : s)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}
