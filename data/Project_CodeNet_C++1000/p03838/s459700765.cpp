#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll x, y;
	cin >> x >> y;
	if ((x >= 0 && y > 0 && x < y)
		|| (x < 0 && y <= 0 && x < y))cout << y - x << endl;
	else if ((x > y && x > 0 && y > 0)
		|| (x > y && x < 0 && y < 0))cout << x - y + 2 << endl;
	else if ((x>0&&y==0)
		|| (x == 0 && y < 0))cout << x-y+1 << endl;
	else cout << abs(abs(x)-abs(y))+1 << endl;
}