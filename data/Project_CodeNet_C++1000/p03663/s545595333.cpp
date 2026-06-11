#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 998244353

ll ans;
string T;

void setting() {
	cin >> ans;
	T = to_string(ans);
}

char judge(ll N) {
	string S = to_string(N);
	if (S <= T && N <= ans)return 'Y';
	if (S > T&& N > ans)return 'Y';
	return 'N';
}

bool ask(ll N) {
	cout << "? " << N << endl;
	char X;
	cin >> X;
	if (X == 'Y')return 1;
	else return 0;
}

int main() {

	ll lv = 9999999999, rv = 99999999999, mid;
	while (rv - lv > 1) {
		mid = (lv + rv) / 2;
		if (ask(mid)) {
			rv = mid;
		}
		else {
			lv = mid;
		}
	}
	ll X = rv;
	while (X % 10 == 0) {
		if (!ask(X + 1)) {
			cout << "! " << X * 10 << endl;
			return 0;
		}
		X /= 10;
	}
	if (X % 10 == 9) {
		if (ask((X - 1) * 10)) {
			cout << "! " << X * 10 << endl;
		}
		else {
			cout << "! " << X << endl;
		}
	}
	else {
		if (ask(X + 1)) {
			cout << "! " << X << endl;
		}
		else {
			cout << "! " << X * 10 << endl;
		}
	}
	
}