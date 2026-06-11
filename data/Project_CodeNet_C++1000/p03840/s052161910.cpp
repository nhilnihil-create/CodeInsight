#include <bits/stdc++.h>
using namespace std;

int main() {
	long long I,O,T,J,L,S,Z;
	long long ans = 0;
	cin >> I >> O >> T >> J >> L >> S >> Z;
	if (!I || !L || !J) {ans = O + 2 * (I / 2) + 2 * (J / 2) + 2 * (L / 2);}
	else {
		ans = max(3 + 2*((I-1)/2) + 2*((J-1)/2) + 2*((L-1)/2),2*(I/2) + 2*(J/2) + 2*(L/2));
		ans += O;
	}
	cout << ans << endl;
}