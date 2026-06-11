#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool qry(ll z) {
	cout<<"? "<<z<<endl;
	fflush(stdout);
	string s;
	cin>>s;
	fflush(stdout);
	return (s == "Y");
}

void spc() {
	ll l = 1;
	while (true) {
		l*=10;
		if (qry(l-1)) {
			cout<<"! "<<(l/10)<<endl; return;
		}
	}
}


int main() {
	ll k = 1; ll d = 1;
	while (true) {
		if (!qry(k)) {
			d = d-1; break;
		}
		d++; k*=10;
		if (d > 14) { spc(); return 0; } // is a power of 10
	}

	ll l = 1;
	for (int i = 1; i <= d; i++) l *= 10;
	ll r = l*10 - 1;
	while (l/10 < r/10) {
		ll mid = (l+r-1)/2;
		if (qry(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	l/=10;
	cout<<"! "<<l<<endl;
	fflush(stdout);
}
