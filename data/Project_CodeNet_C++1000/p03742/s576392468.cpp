#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void maxi(int &a, int b) {
	a = max(a,b);
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	ll X, Y;
	cin >> X >> Y;
	if (max(X-Y, Y-X) <= 1) {
		cout << "Brown" << "\n";	
	} else {
		cout << "Alice" << "\n";
	}
}

