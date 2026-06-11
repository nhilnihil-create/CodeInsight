#include <iostream>
using namespace std;
int main(void) {
	int x;
	cin >> x;
	int t = 0, ans = 0;
	while (ans < x) {
		++t;
		ans += t;
	}
	cout << t << endl;
	return 0;
}