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

	int H, W;
	string *C;

	cin >> H >> W;

	C = new string[H];

	for (int i = 0; i < H; i++) {
		cin >> C[i];
	}

	for (int i = 0; i < H; i++) {
		cout << C[i] << "\n" << C[i] << "\n";
	}

	return 0;
}
