#include <bits/stdc++.h>
using namespace std;


int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	string ans = "";

	ans += string(x2 - x1, 'R');
	ans += string(y2 - y1, 'U');
	ans += string(x2 - x1, 'L');
	ans += string(y2 - y1, 'D');
	
	ans += 'L';
	ans += string(y2 - y1 + 1, 'U');
	ans += string(x2 - x1 + 1, 'R');
	ans += 'D';

	ans += 'R';
	ans += string(y2 - y1 + 1, 'D');
	ans += string(x2 - x1 + 1, 'L');
	ans += 'U';

	cout << ans << endl;
	return 0;

}
