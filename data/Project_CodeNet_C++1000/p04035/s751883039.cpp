#include<iostream>
using namespace std;
int main() {
	//A
	/*
	int a, b;
	cin >> a;
	cin >> b;

	if ((a <= 0) && (b >= 0)) {
		cout << "Zero";
	}
	else if(a>0){
		cout << "Positive";
	}
	else {
		if ((b - a) % 2 == 0) {
			cout << "Negative";
		}
		else {
			cout << "Positive";
		}
	}
	
	return 0;*/

	//B
	/*int n, m;
	int x;
	int y;
	int flag[100000];
	int ball[100000];
	cin >> n;
	cin >> m;
	int i,c;
	
	for (i = 0; i < 100000; i++) {
		flag[i] = 0;
		ball[i] = 1;
	}
	flag[0] = 1;
	for (i = 0; i < m; i++) {
		cin >> x;
		cin >> y;

		if (flag[x-1] == 1) {
			flag[y-1] = 1;
		}
		ball[x - 1]--;
		if (ball[x - 1] == 0) {
			flag[x - 1] = 0;
		}
		ball[y - 1]++;
	}
	c = 0;
	for (i = 0; i < n; i++) {
		if (flag[i] == 1) {
			c++;
		}
	}
	cout << c;
	return 0;*/
	
	//C
	int n,l;
	cin >> n;
	cin >> l;
	long long int a[100000];
	int i;
	int flag;
	flag = -1;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++) {
		if (a[i] + a[i + 1] >= l) {
			flag = i;
			break;
		}
	}

	if (flag == -1) {
		cout << "Impossible\n";
	}
	else {
		cout << "Possible\n";
		for (i = 0; i < flag; i++) {
			cout << i+1;
			cout <<'\n';
		}
		for (i = n-2; i >= flag; i--) {
			cout << i+1;
			cout << '\n';
		}
	}

	return 0;
}