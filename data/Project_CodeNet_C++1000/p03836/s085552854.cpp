#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void c_back_and_forth(void) {
	int sx, sy, tx, ty;

	int dx, dy;

	cin >> sx >> sy >> tx >> ty;

	//
	dx = tx - sx;
	dy = ty - sy;
	// 1回目 往路
	for (int i = 0; i < abs(dy); i++) {
		if (dy < 0) cout << "D";
		else        cout << "U";
	}
	for (int i = 0; i < abs(dx); i++) {
		if (dx < 0) cout << "L";
		else        cout << "R";
	}
	
	// 1回目復路
	dx = sx - tx;
	dy = sy - ty;
	for (int i = 0; i < abs(dy); i++) {
		if (dy < 0) cout << "D";
		else        cout << "U";
	}
	for (int i = 0; i < abs(dx); i++) {
		if (dx < 0) cout << "L";
		else        cout << "R";
	}

	// 2回目往路
	dx = tx - sx;
	if (dx > 0) {
		dx = tx - (sx - 1);
		cout << "L";
	}
	else {
		dx = tx - (sx + 1);
		cout << "R";
	}
	dy = ty - sy;
	if (dy > 0) {
		dy += 1;
	}
	else {
		dy -= 1;
	}
	for (int i = 0; i < abs(dy); i++) {
		if (dy > 0) cout << "U";
		else        cout << "D";
	}
	for (int i = 0; i < abs(dx); i++) {
		if (dx > 0) cout << "R";
		else        cout << "L";
	}
	if (dy > 0) cout << "D";
	else        cout << "U";

	dx = sx - tx;
	if (dx < 0) {
		dx -= 1;
		cout << "R";
	}
	else {
		dx += 1;
		cout << "L";
	}
	dy = sy - ty;
	if (dy < 0) {
		dy -= 1;
	}
	else {
		dy += 1;
	}
	for (int i = 0; i < abs(dy); i++) {
		if (dy > 0) cout << "U";
		else        cout << "D";
	}
	for (int i = 0; i < abs(dx); i++) {
		if (dx > 0) cout << "R";
		else        cout << "L";
	}

	if (dy < 0) cout << "U";
	else        cout << "D";
}
int main()
{
    c_back_and_forth();

    return 0;
}
