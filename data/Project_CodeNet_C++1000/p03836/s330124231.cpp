#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx;
	int dy = ty - sy;
	for (int i=0; i<dx; i++) cout << 'R';
	for (int i=0; i<dy; i++) cout << 'U';
	for (int i=0; i<dx; i++) cout << 'L';
	for (int i=0; i<dy; i++) cout << 'D';
	cout << 'D';
	for (int i=0; i<=dx; i++) cout << 'R';
	for (int i=0; i<=dy; i++) cout << 'U';
	cout << 'L';
	cout << 'U';
	for (int i=0; i<=dx; i++) cout << 'L';
	for (int i=0; i<=dy; i++) cout << 'D';
	cout << 'R';
}