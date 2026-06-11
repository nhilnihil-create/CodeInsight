#include<bits/stdc++.h>
using namespace std;
#define ll long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	for (int i = 1; i <= ty - sy; i++) {
		cout << "U";
	}
	for (int i = 1; i <= tx - sx; i++) {
		cout << "R";
	}
	for (int i = 1; i <= ty - sy; i++) {
		cout << "D";
	}
	for (int i = 1; i <= tx - sx; i++) {
		cout << "L";
	}
	cout << "L";
	for (int i = 1; i <= ty - sy + 1; i++) {
		cout << "U";
	}
	for (int i = 1; i <= tx - sx + 1; i++) {
		cout << "R";
	}
	cout << "D";
	cout << "R";
	for (int i = 1; i <= ty - sy + 1; i++) {
		cout << "D";
	}
	for (int i = 1; i <= tx - sx + 1; i++) {
		cout << "L";
	}
	cout << "U";

}