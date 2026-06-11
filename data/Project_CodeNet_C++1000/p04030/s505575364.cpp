#include<iostream>
using namespace std;
int main() {

	//B
	string s;
	int i;
	cin >> s;
	int num = 0;
	char a[10];
	for (i = 0; i < s.length(); i++) {
		if (s[i] == '0' || s[i] == '1') {
			a[num] = s[i];
			num++;
		}
		else {
			if (num > 0)num--;
		}
	}
	for (i = 0; i < num; i++) {
		cout << a[i];
	}
	cout << endl;
	return 0;

	//C
	/*int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum;
	int min = 100000000;
	for (int i = -100; i <= 100; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum = sum + (i - a[j]) * (i - a[j]);
		}
		if (sum < min)min = sum;
	}
	cout << min << endl;
	return 0;*/


	//D
	/*
	string s;
	cin >> s;
	int i, j, k;
	int ab[26];
	for (i = 0; i < 26; i++) {
		ab[i] = 0;
	}
	for (j = 0; j < s.length() - 1; j++) {
		if (s[j] == s[j + 1]) {
			cout << j + 1 << ' ' << j + 2 << endl;
			return 0;
		}
		else if (j < s.length() - 2) {
			if (s[j] == s[j + 2]) {
				cout << j + 1 << ' ' << j + 3 << endl;
				return 0;
			}
		}
	}
	cout << -1 << ' ' << -1 << endl;
	return 0;*/
}