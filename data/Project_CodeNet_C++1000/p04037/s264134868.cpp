#include <iostream>
#include <algorithm>

using namespace std;

int hrpe[100005];

int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) cin >> hrpe[i];
	sort (hrpe, hrpe+n);
	int zadnji = -1;
	for (int i=0;i<n;i++) {
		int b = hrpe[i]-1;
		int u = n-i-1;
		if ((b+u) % 2 == 0) {
			if (u <= (b+u)/2) {
				if (zadnji == -1) {
					cout << "Second";
					break;
				}
				else if (hrpe[i-1] != hrpe[i]) {
					cout << "Second";
					break;
				}
				else if (!zadnji) {
					cout << "Second";
					break;
				}
			}
		}
		else {
			if (u <= (b+u)/2+1) {
				if (zadnji == -1) {
					cout << "First";
					break;
				}
				else if (hrpe[i-1] != hrpe[i]) {
					cout << "First";
					break;
				}
				else if (zadnji) {
					cout << "First";
					break;
				}
			}
		}
		if (i != 0) {
			if (hrpe[i-1] != hrpe[i]) {
				zadnji = (b+u)%2;
			}
		}
		else {
			zadnji = (b+u) % 2;
		}
	}
	return 0;
}
