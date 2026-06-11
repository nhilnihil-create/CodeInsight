#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int H, W;
	scanf("%d %d", &H, &W);
	string C[100];
	for (int i = 0; i < H; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < H; i++) {
		cout << C[i] << "\n";
		cout << C[i] << "\n";
	}

	return 0;
}
