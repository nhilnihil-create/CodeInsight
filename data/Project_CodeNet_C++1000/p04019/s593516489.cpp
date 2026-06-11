#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;


int main() {

	string s;
	bool N = false, S = false, W = false, E = false;


	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') {
			N = true;
		}
		if (s[i] == 'S') {
			S = true;
		}
		if (s[i] == 'E') {
			E = true;
		}
		if (s[i] == 'W') {
			W = true;
		}
	}

	if ((N == S) && (E == W)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}



	return 0;
}
