#include <bits/stdc++.h>
using namespace std;

int w, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> w >> a >> b;
	
	if (max(a, b) <= min(a+w, b+w)) {
		cout << 0 << '\n';
	}
	else {
		cout << min(abs((a+w) - b), abs(a - (b+w))) << '\n';
	}

    return 0;
}