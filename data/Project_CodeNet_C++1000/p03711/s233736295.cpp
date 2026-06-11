#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define PI 3.141592653589793238
#define INF 1050000000

using namespace std;



//cout << fixed << setprecision(15) << << endl;
//cout << << endl;

int main() {

	int x, y;

	cin >> x >> y;

	vector<int> A = { 1,3,5,7,8,10,12 }, B = { 4,6,9,11 }, C = { 2 };

	int opx = 0, opy = 0;

	for (int i = 0; i < 4; i++) {
		if (x == B[i]) {
			opx = 1;
		}
		if (y == B[i]) {
			opy = 1;
		}
	}

	if (x == 2||y==2) {
		cout << "No" << endl;
	}
	else if (opx == opy) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	return 0;
}