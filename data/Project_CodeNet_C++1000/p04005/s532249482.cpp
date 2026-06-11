#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a,b,c; cin >> a >> b >> c;
	if(a%2==0||b%2==0||c%2==0) {
		cout << 0 << endl;
		return 0;
	}
	ll A=b*c;
	ll B=a*c;
	ll C=a*b;
	cout << min(A,min(B,C)) << endl;
}