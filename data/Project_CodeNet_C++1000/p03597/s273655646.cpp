#include <bits/stdc++.h>
using namespace std;

int main() {
	int cell, size, colorCell;
	cin >> size;
	cin >> colorCell;
	cell = size*size;
	cout << cell - colorCell << endl;
	return 0;
}