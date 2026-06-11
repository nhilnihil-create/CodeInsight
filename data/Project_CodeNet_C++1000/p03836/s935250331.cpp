#include<bits/stdc++.h>

using namespace std;

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	for (int i = 0; i < ty - sy; ++i) cout << 'U';
	for (int i = 0; i < tx - sx; ++i) cout << 'R';
	for (int i = 0; i < ty - sy; ++i) cout << 'D';
	for (int i = 0; i < tx - sx; ++i) cout << 'L';
	cout << 'L'; 
	for (int i = 0; i < ty - sy; ++i) cout << 'U';
	cout << "UR";
	for (int i = 0; i < tx - sx; ++i) cout << 'R';
	cout << "DR";
	for (int i = 0; i < ty - sy; ++i) cout << 'D';
	cout << "DL";
	for (int i = 0; i < tx - sx; ++i) cout << 'L';
	cout << 'U';
	return 0;
}