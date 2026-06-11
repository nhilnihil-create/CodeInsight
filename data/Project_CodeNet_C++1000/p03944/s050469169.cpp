#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_sunuke_easy(void) {
	int w, h, n;
	int x[110], y[110], a[110];
	int area[110][110] = { 0 };
	cin >> w >> h >> n;
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i] >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= h; j++) {
			for (int k = 0; k <= w; k++) {
				if (a[i] == 1) {
					if (k < x[i]) area[j][k] = 1;
				}
				else if (a[i] == 2) {
					if (k >= x[i]) area[j][k] = 1;
				}
				else if (a[i] == 3) {
					if (j < y[i]) area[j][k] = 1;
				}
				else {
					if (j >= y[i]) area[j][k] = 1;
				}
			}
		}
      	}
	int cnt = 0;
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			if (area[j][i] == 0) cnt++;
			//cout << area[j][i];
		}
		//cout << endl;
	}
	cout << cnt << endl;
}

int main()
{
	b_sunuke_easy();
    return 0;
}
