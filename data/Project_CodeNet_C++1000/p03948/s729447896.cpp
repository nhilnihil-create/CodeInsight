#include<iostream>
using namespace std;
int b[100000];
int main() {

	//C
	/*string s;
	int i;
	cin >> s;
	int k;
	if (s[0] == 'B') {
		k = 0;
	}
	else {
		k = 1;
	}
	int  counter = 0;
	for (i = 1; i < s.size(); i++) {
		if ((s[i] == 'W')&&(k == 0)) {
			k = 1;
			counter++;
		}
		if ((s[i] == 'B') && (k == 1)) {
			k = 0;
			counter++;
		}
	}

	cout << counter << endl;
	return 0;*/

	//D
	int n,t;
	cin >> n>> t;
	int i, a[100000];
	//int k = 1;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	//b[0] = -k;
	int dis;
	int min, max;
	min = a[0]; max = a[0]; dis = 0;
	int minchange = 0;
	for (i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			max = a[i];
			//minchange = 0;
		}
		if (a[i] > max) {
			max = a[i];
			if (max - min > dis)dis = max - min;
			//k++;

		}
	}
	int counter = 0;
	min = a[0]; max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			max = a[i];
		}
		if (a[i] > max) {
			max = a[i];
			if (max - min == dis)counter++;
		}
	}
	cout << counter << endl;
	return 0;
}