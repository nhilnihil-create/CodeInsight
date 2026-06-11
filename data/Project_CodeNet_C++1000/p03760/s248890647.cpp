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

	string O, E;

	cin >> O >> E;

	for (int i = 0; i < O.size(); i++) {
		cout << O[i];
		if (E[i] != '\0') {
			cout << E[i];
		}
	}

	return 0;
}
