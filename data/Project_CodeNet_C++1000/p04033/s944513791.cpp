#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	scanf("%d %d", &a, &b);
	if(b >= 0 && a < 0) {
		printf("%s\n", "Zero");
	}else if(a > 0) {
		printf("%s\n", "Positive");
	}else if(a < 0 && b < 0) {
		if((b - a) % 2 == 0) {
			printf("%s\n", "Negative");
		}else {
			printf("%s\n", "Positive");
		}
	}
}