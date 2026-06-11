#include <bits/stdc++.h>
using namespace std;

int H, W, P, Q;

int main() {
	cin >> H >> W >> P >> Q;
	if(!(H%P) && !(W%Q)) {
		puts("No");
		return 0;
	}
	puts("Yes");
	if(H%P) {
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++)
				printf("%d ", i%P ? H+1 : -(P-1)*(H+1)-1);
			puts("");
		}
	} else if(W%Q) {
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++)
				printf("%d ", j%Q ? W+1 : -(Q-1)*(W+1)-1);
			puts("");
		}
	}
	return 0;
}