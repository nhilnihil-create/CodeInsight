#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printLine(int width) {
	for (int i = 0; i < width; i++) {
		printf("#");
	}
	printf("\n");
}

void printStrLine(int width, string s) {
	cout << "#" << s << "#" << endl;
}

int main(void) {
	int H, W;
	scanf("%d %d", &H, &W);
	string a[100];
	for (int i = 0; i < H; i++) {
		cin >> a[i];
	}
	printLine(W + 2);
	for (int i = 0; i < H; i++) {
		printStrLine(W, a[i]);
	}

	printLine(W + 2);

	return 0;
}
