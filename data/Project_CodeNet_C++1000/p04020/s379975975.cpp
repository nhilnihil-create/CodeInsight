#include<iostream>
using namespace std;
int main() {
	//A
	/*char a[1001];
	int i;
	for (i = 0; i < 1001; i++) {
		a[i] = '0';
	}
	cin >> a;
	int n, s, w, e;
	n = 0;
	s = 0;
	w = 0;
	e = 0;
	for (i = 0; i < 1001; i++) {
		if (a[i] == 'N') {
			n = 1;

		}
		else if (a[i] == 'S') {
			s = 1;
		}
		else if (a[i] == 'W') {
			w = 1;
		}
		else if (a[i] == 'E') {
			e = 1;
		}
	}
	if ((n == s) && (w == e)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;*/

	//B
	int n;
	int a[100000];
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long int c;
	c = 0;
	int flag;
	flag = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			flag = 0;
		}
		else {
			if (flag == 0) {
				if (a[i] % 2 == 0) {
					c = c + a[i] / 2;
				}
				else {
					flag = 1;
					c = c + (a[i] - 1) / 2;

				}
			}
			else {
				if (a[i] % 2 == 0) {
					c = c + a[i] / 2;
				}
				else {
					flag = 0;
					c = c + (a[i] + 1) / 2; 
				}
			}
		}
	}
	cout << c;
	return 0;

	//C

	/*int n;
	cin >> n;
	int a[100000],b[100000],c;
	int i,j;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = 0;
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
				c = b[j];
				b[j] = (b[j + 1] + 1) % 2;
				b[j + 1] = (c + 1) % 2;
			}
		}
	}
	c = 0;
	for (i = 0; i < n; i++) {
		if (b[i] == 1) {
			c++;
		}
	}
	cout << c / 2;
	return 0;*/
}
