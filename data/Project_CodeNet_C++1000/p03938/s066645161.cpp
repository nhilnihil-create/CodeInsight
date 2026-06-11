#include<iostream>
using namespace std;
int main() {
	//A
	/*
	int h;
	int w;
	cin >> h;
	cin >> w;

	char a[9][9];
	int i, j;
	int count1 = 0;
	int count2 = 0;
	for (i = 0; i < h+1; i++) {
		for (j = 0; j < w+1; j++) {
			a[i][j]='.';
		}
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	i = 0;
	j = 0;
	while ((i < h) && (j < w)){
		if (a[i+1][j] == '#') {
			a[i][j] = '.';
			i++;
		}
		else if (a[i][j + 1] == '#') {
			a[i][j] = '.';
			j++;
		}
		else {
			break;
		}
	} 
	a[i][j] = '.';
	if ((i >= h - 1) && (j >= w - 1)) {
		for (count1 = 0; count1 < h; count1++) {
			for (count2 = 0; count2 < w; count2++) {
				if (a[count1][count2] == '#') {
					cout << "Impossible";
					return 0;
				}
			}
		}
		cout << "Possible";
		return 0;
	}
	else {
		cout << "Impossible";
		return 0;
	}
		

	return 0;*/

	int n;
	int p[20001];
	int pin[20001];
	cin >> n;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> p[i];
		pin[p[i]] = i;
	}
	int a[20001] , b[20001];
	for (i = 1; i <= n; i++) {
		a[i] = i * 20001 + pin[i];
		b[i] = (20001 - i) * 20001 + pin[i];
	}
	for (i = 1; i <= n; i++) {
		cout << a[i];
		cout<<' ';
	}
	cout << '\n';
	for (i = 1; i <= n; i++) {
		cout << b[i];
		cout << ' ';
	}
	return 0;
}