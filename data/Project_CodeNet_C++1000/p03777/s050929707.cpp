#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	char a, b; cin >> a >> b;
	char ans;
	if (a == 'H' && b == 'H') ans = 'H';
	if (a == 'H' && b == 'D') ans = 'D';
	if (a == 'D' && b == 'H') ans = 'D';
	if (a == 'D' && b == 'D') ans = 'H';
	cout << ans << endl;
	return 0;
}