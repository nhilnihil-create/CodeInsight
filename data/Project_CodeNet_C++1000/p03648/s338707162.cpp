#include<iostream>

using namespace std;

int main() {
	long long k;
	cin >> k;
	long long x, y;
	if (k >= 50) {
		cout << 50 << endl;
		x = k / 50;
		y = k % 50;
		if (1 <= y) {
			cout << 49 + x + 51 - y;
		}
		else { cout << 49 + x - y; }
		for (int i = 2; i <= 50; i++) {
			if (i <= y) {
				cout << ' ' << 49 + x + 51 - y ;
			}
			else {
				cout << ' ' << 49 + x - y ;
			}
		}
	}
	else if(k!=0){
		cout << 50 << endl;
		cout << 50 * k;
		for (int i = 2; i <= 50; i++) {
			cout << ' ' << 0;
		}
	}
	else { cout << 2 << endl << 0 << ' ' << 0; }
	cout << endl;
}