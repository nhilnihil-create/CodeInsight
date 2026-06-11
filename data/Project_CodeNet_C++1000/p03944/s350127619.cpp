#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;


int main(){
	int w, h, n;

	cin >> w >> h >> n;

	vector<int> xx(n);
	vector<int> yy(n);
	vector<int> aa(n);

	for (int i = 0; i < n; i++)cin >> xx[i] >> yy[i] >> aa[i];

	vector<vector<int> > xxxx(2, vector<int>(n+1));
	vector<vector<int> > yyyy(2, vector<int>(n+1));

	xxxx[0][0] = 0;
	xxxx[1][0] = w;
	yyyy[0][0] = 0;
	yyyy[1][0] = h;

	for (int i = 0; i < n; i++) {
		if (aa[i] == 1) {
			if (xxxx[0][i] < xx[i]) {
				xxxx[0][i + 1] = xx[i];
			}
			else {
				xxxx[0][i + 1] = xxxx[0][i];
			}

			xxxx[1][i + 1] = xxxx[1][i];
			yyyy[0][i + 1] = yyyy[0][i];
			yyyy[1][i + 1] = yyyy[1][i];
		}
		else if (aa[i] == 2) {

			if (xxxx[1][i] > xx[i]) {
				xxxx[1][i + 1] = xx[i];
			}
			else {
				xxxx[1][i + 1] = xxxx[1][i];
			}

			xxxx[0][i + 1] = xxxx[0][i];
			yyyy[0][i + 1] = yyyy[0][i];
			yyyy[1][i + 1] = yyyy[1][i];
		}
		else if (aa[i] == 3) {
			xxxx[0][i + 1] = xxxx[0][i];
			xxxx[1][i + 1] = xxxx[1][i];
			if (yyyy[0][i]<yy[i]) {
				yyyy[0][i + 1] = yy[i];
			}
			else {
				yyyy[0][i + 1] = yyyy[0][i];
			}

			yyyy[1][i + 1] = yyyy[1][i];
		}
		else {
			xxxx[0][i + 1] = xxxx[0][i];
			xxxx[1][i + 1] = xxxx[1][i];
			
			if (yyyy[1][i] > yy[i]) {
				yyyy[1][i + 1] = yy[i];
			}
			else {
				yyyy[1][i + 1] = yyyy[1][i];
			}

			yyyy[0][i + 1] = yyyy[0][i];
		}
			
	}

	if ((xxxx[1][n] - xxxx[0][n])>0 && (yyyy[1][n] - yyyy[0][n]) > 0)
		cout << (xxxx[1][n] - xxxx[0][n]) * (yyyy[1][n] - yyyy[0][n]) << endl;
	else
		cout << 0 << endl;

	return 0;
}