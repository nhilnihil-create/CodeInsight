#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	
	if (b >= a) {
		if (a + w >= b) {
			cout << 0;
		}
		else {
			cout << b - (a + w);
		}
	}
	else {
		if (b + w >= a) {
			cout << 0;
		}
		else {
			cout << a - (b + w);
		}
	}
	
	return 0;
}
