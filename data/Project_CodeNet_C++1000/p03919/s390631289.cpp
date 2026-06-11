#include "bits/stdc++.h"
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	char alpha[27] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string a;
	for ( int i = 1; i <= h; i++ ) {
		for ( int j = 1; j <= w; j++ ) {
			cin >> a;
			if ( a == "snuke" ) {
				cout << alpha[j] << i << endl;
			}
		}
	}
}
