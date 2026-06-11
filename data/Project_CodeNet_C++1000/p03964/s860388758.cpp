#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll N,T,A,vT=1,vA=1;

	cin >> N;
	rep(i,N) {
		ll x,y,n;
		cin >> T >> A;

		x = vT/T;
		if(vT%T) ++x;
		y = vA/A;
		if(vA%A) ++y;
		n = max(x, y);

		vT=n*T, vA=n*A;
	}

	cout << vT+vA << endl;
}