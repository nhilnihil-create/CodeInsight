#include <bits/stdc++.h>
using namespace std;

char a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> a >> b;
	if (a == 'H') {
		cout << b << '\n';
	}
	else {
		if (b == 'H') {
			cout << 'D' << '\n';
		}
		else {
			cout << 'H' << '\n';
		}
	}

    return 0;
}