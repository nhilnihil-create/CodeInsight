#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map> 
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
const ll MD = 1000000007;

/* sample input

*/

int main()
{
	int h, w,d;
	cin >> h >> w >> d;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			int posx, posy;
			int x = i + j;
			int y = -j + i + w;
			posx = x/d % 2;
			posy = y/d % 2;

			char color[2][2];
			color[0][0] = 'R';
			color[0][1] = 'Y';
			color[1][0] = 'G';
			color[1][1] = 'B';

			cout << color[posx][posy];

			if (j == w - 1) {
				cout << endl;
			}
		}
	}

	return 0;
}