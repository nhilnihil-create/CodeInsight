#include <iostream>
using namespace std;
int a[13];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	a[1] = a[3] = a[5] = a[7] = a[8] = a[10] = a[12] = 1;
	a[4] = a[6] = a[9] = a[11] = 2;
	a[2] = 3;
	int x, y;
	cin >> x >> y;
	if (a[x] == a[y])cout << "Yes\n";
	else cout << "No\n";
}