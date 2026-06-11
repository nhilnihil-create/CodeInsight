#include <bits/stdc++.h>
#define SZ(v) ((int)((v).size()))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,c;
	cin >> a >> b >> c;
	if ((a%2)*(b%2)*(c%2) == 0) cout << "0\n";
	else cout << min(a*b, min(b*c,a*c)) << "\n";
}
