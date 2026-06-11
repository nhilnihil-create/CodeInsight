#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//#include <bits/stdc++.h>


int main() {
	int n, l, r,y;
	cin >> n;
	y = 0;
	rep(i, n) {
		
		cin >> l >> r;
		y += (r - l + 1);
		
	}
	cout << y << endl;
	return 0;
}
