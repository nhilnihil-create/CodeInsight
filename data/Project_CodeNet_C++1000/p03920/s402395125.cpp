#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int b;
	cin >> b;
	int s = 0;
	for (int a = 1;; a++) {
		s += a - 1;
		if (s + a >= b) {
			for (int j = a; j > 0; j--) {
				if (b >= j) {
					b -= j;
					printf("%d\n", j);
				}
				if (b == 0)return 0;
			}
		}
	}
}