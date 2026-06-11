#include<bits/stdc++.h>

const int LEN = 1e5 + 7;

char st[LEN];
int st1[LEN], st2[LEN], N;
// b = 2, d = 3, p = 4, q = 5
int main() {
	scanf("%s",st);
	N = strlen(st);
	for(int i = 0; i < N; ++i) {
		int x;
		switch(st[i]) {
			case 'b': x = 2; break;
			case 'd': x = 3; break;
			case 'p': x = 4; break;
			case 'q': x = 5; break;
		}
		st1[i + 1] = x;
		st2[N - i] = (x ^ 1);
	}
	for(int i = 1; i <= N; ++i) {
		if(st1[i] != st2[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}