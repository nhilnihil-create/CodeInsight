#include <bits/stdc++.h>
using namespace std;

int h, w;
string a[1001];

int main () {
	cin >> h >> w;
	for (int i = 0; i < h; i++){
		cin >> a[i];
	}
	for (int i = 0; i < w+2; i++){
		cout << "#";
	}
	for (int i = 0; i < h; i++){
		cout << endl << "#" << a[i] << "#";
	}
	cout << endl;
	for (int i = 0; i < w+2; i++){
		cout << "#";
	}
}