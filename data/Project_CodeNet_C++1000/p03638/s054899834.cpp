#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int h, w, n, a;
	cin >> h >> w >> n;
	int b[h][w] = {};
	int x = 0, y = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> a;
		for (int j = 0 ; j < a ; j++) {
			b[x][y] = i + 1;
			y++;
			if (y == w) {
				y = 0;
				x++;
			}
		}
		
	}
	for (int i = 0 ; i < h ; i++) {
		if (i % 2 == 0) {
			for (int j = 0 ; j < w ; j++) cout << b[i][j] << ' ';
		}
		else {
			for (int j = w - 1 ; j >= 0 ; j--) cout << b[i][j] << ' ';
		}
		cout << endl;
	}
}