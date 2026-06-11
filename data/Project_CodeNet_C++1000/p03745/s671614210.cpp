#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	int counter = 0;
	int in1;
	int oldin=0;
	int zoukaflg = 0;
	for (int i = 0; i < n; i++) {
		cin >> in1;
		if (oldin == 0) {
			oldin = in1;
			counter++;
		}
		else {
			if (zoukaflg == 0) {
				if (in1 != oldin) {
					zoukaflg = (in1 - oldin) / (abs(in1 - oldin));
					oldin = in1;
				}
				else {
					zoukaflg = 0;
					oldin = in1;
				}
			}
			else {
				if (zoukaflg > 0 && in1 >= oldin) {
					oldin = in1;
				}
				else if (zoukaflg > 0 && in1 < oldin) {
					oldin = in1;
					zoukaflg = 0;
					counter++;
				}
				else if (zoukaflg < 0 && in1 <= oldin) {
					oldin = in1;
				}
				else {
					oldin = in1;
					zoukaflg = 0;
					counter++;
				}
			}
		}
	}

	cout << counter << endl;
	return 0;
}