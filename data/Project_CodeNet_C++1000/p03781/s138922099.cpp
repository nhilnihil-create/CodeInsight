#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ll X;
	cin >> X;

	int ans = 1;
	ll cum = ans;
	while(cum < X) {
		cum += ++ans;
	}
	cout << ans << endl;

	return 0;
}
