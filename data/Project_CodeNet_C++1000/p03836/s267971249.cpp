#include<iostream>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
#include<cmath>
#include<map>
#include <limits>
# include <iomanip>
#include <queue>
#define INF 1000000000000000009;
#define WARU 1000000007;

using namespace std;
int gcd(int a, int b) {
	while (a % b != 0) {
		int c = 0;
		c = a % b;
		a = b;
		b = c;
	}
	return  b;
}

int main() {
	int sx = 0, sy = 0, tx = 0, ty = 0;
	//int a[100];
	cin >> sx >> sy >> tx >> ty;
	for (int i = 0; i < tx-sx; i++) {
		cout << "R";
	}
	for (int i = 0; i < ty - sy; i++) {
		cout << "U";
	}
	for (int i = 0; i < tx - sx; i++) {
		cout << "L";
	}
	for (int i = 0; i < ty - sy+1; i++) {//+1は二回目で外周に移動するため
		cout << "D";
	}
	for (int i = 0; i < tx - sx+1; i++) {
		cout << "R";
	}
	for (int i = 0; i < ty - sy+1; i++) {
		cout << "U";
	}
	cout << "LU";
	for (int i = 0; i < tx - sx+1; i++) {
		cout << "L";
	}
	for (int i = 0; i < ty - sy+1; i++) {
		cout << "D";
	}
	cout << 'R' << endl;
	return 0;
}