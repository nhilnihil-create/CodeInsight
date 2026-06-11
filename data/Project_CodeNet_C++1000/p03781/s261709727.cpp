#include <bits/stdc++.h>

using namespace std;

int main() {
	int N,S = 0;
	scanf("%d",&N);
	for (int i=1;;i++) {
		S += i;
		if (S >= N) {
			printf("%d\n",i);
			return 0;
		}
	}
}