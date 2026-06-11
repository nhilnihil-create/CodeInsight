#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	string S;
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == ',') S[i] = ' ';
	}
	cout << S << "\n";

	return 0;
}
