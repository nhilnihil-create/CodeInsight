#include "bits/stdc++.h"
using namespace std;

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int x = tx - sx;
	int y = ty - sy;
	string s;
	for (int i = 0;i<x;++i) {
		s += "R";
	}
	for (int i = 0;i<y;++i) {
		s += "U";
	}
	for (int i = 0; i < x; ++i) {
		s += "L";
	}
	for (int i = 0; i < y; ++i) {
		s += "D";
	}
	s += "D";	
	for (int i = 0; i <= x; ++i) {
		s += "R";
	}
	for (int i = 0; i <= y; ++i) {
		s += "U";
	}
	s += "L";
	s += "U";
	for (int i = 0; i <= x; ++i) {
		s += "L";
	}
	for (int i = 0; i <= y; ++i) {
		s += "D";
	}
	s += "R";
	cout << s << endl;
	return 0;
}