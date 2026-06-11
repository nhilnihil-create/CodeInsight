#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	long long S = 1;
	for (int i = 0; i < 15; i++) {
		cout << "? " << S << endl;
		string P; cin >> P; if (P == "N") break;
		S *= 10;
	}
	if (S >= (1LL << 40)) {
		S = 10;
		for (int i = 0; i < 14; i++) {
			cout << "? " << S - 1 << endl;
			string P; cin >> P; if (P == "Y") break; S *= 10;
		}
		cout << "! " << (S / 10) << endl;
		return 0;
	}
	S /= 10;
	long long L = S, R = S * 10, M, minx = S - 1;
	for (int i = 0; i < 50; i++) {
		M = (L + R) / 2;
		cout << "? " << min(M, S * 10 - 1) * 10 << endl;
		string P; cin >> P;
		if (P == "Y") R = M;
		else { L = M; minx = max(minx, M); }
	}
	cout << "! " << (minx + 1) << endl;
	return 0;
}