#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int N;
	scanf("%d", &N);
	string S;
	cin >> S;
	int x = 0;
	int xMax = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'I') x++;
		else x--;
		xMax = max(xMax, x);
	}
	printf("%d\n", xMax);
	return 0;
}
