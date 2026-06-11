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

	int X, A, B;

	cin >> X >> A >> B;

	if (X >= A) {
		if (X >= B) {
			cout << A + B << endl;
		}
		else {
			cout << A + X << endl;
		}
	}
	else {
		if (A >= B) {
			cout << X + B << endl;
		}
		else {
			cout << A + X << endl;
		}
	}


	return 0;
}