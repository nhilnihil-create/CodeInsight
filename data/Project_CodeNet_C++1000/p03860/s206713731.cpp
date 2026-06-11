#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	string S[3];
	for (int i = 0; i < 3; i++) {
		cin >> S[i];
	}
	cout << "A" << S[1][0] << "C" << "\n";
	return 0;
}
