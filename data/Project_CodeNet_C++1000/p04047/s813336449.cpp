#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int L[200];
	int i,j,c;
	for (i = 0; i < 2 * n; i++) {
		cin >> L[i];
	}
	//ソート
	for (i = 0; i < 2 * n - 1; i++) {
		for (j = 0; j < 2 * n -1 - i; j++) {
			if (L[j] < L[j + 1]) {
				c = L[j];
				L[j] = L[j + 1];
				L[j + 1] = c;
			}
		}
	}
	c = 0;
	for (i = 1; i < 2 * n; i = i + 2) {
		c = c + L[i];
	}
	cout << c;
	return 0;
}