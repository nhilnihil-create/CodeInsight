#include <iostream>
#include <string>
#include <stdio.h>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	const int dx = tx - sx, dy = ty - sy;

	// Path 1
	for (int d = 0; d < dy; d++)cout << "U";
	for (int d = 0; d < dx; d++)cout << "R";


	// Path 2
	for (int d = 0; d < dy; d++)cout << "D";
	for (int d = 0; d < dx; d++)cout << "L";

	// Path 3
	cout << "L";
	for (int d = 0; d < dy+1; d++)cout << "U";
	for (int d = 0; d < dx+1; d++)cout << "R";
	cout << "D";

	// Path 4
	cout << "R";
	for (int d = 0; d < dy+1; d++)cout << "D";
	for (int d = 0; d < dx+1; d++)cout << "L";
	cout << "U";

	// EndLine
	cout << endl;
	return 0;
}