#include<iostream>
using namespace std;
int main() {
	long long a, b, c; cin >> a >> b >> c;
	if (a == b && b == c && a % 2 == 0) {
		cout << "-1" << endl;
		return 0;
	}
	long long cnt = 0;
	while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		long long A = a/2, B = b/2, C = c/2;
		a = B + C;
		b = C + A;
		c = A + B;
		cnt++;
	}
	cout << cnt << endl;
}