#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (abs(x - y) > 1) {
		printf("Alice\n");
	} else {
		printf("Brown\n");
	}
}